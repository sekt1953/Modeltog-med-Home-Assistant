//Program Turntable.ino
//Made by Allan Olsen, SMJK
//First release 20190616
//Version 20230627

typedef unsigned char UBYTE;
typedef signed char BYTE;
typedef unsigned short int UWORD;
typedef signed short int WORD;
typedef unsigned long int ULONG;
typedef signed long int LONG;
typedef unsigned long TIME_T;

enum DIRECTION {NEUTRAL=0, REVERSE, FORWARD, BOTH_DIRECTION};
enum STATE {OFF=0, ON};

void setup();
void loop();
void split_word(UWORD val, UBYTE *a, UBYTE *b);
void split_long(ULONG val, UBYTE *a, UBYTE *b, UBYTE *c);
void join_word(UWORD *val, UBYTE a, UBYTE b);
void join_long(ULONG *val, UBYTE a, UBYTE b, UBYTE c);
void Save_EEprom(ULONG *v);
void Read_EEprom(ULONG *v);
void stepper_move(ULONG steps, DIRECTION dir);
bool chk_cancel_move();
void calc_move(int new_pos, DIRECTION dir);
void chk_button_direction();
void chk_button_move();
void chk_button_halfturn();
bool chk_button_save_pos(int x);
bool reset_stepper();
void alarm();
void setup_routine();
UBYTE calc_index(UWORD val);
void calc_index_init();
void chk_led_move();
void SetSpeedStep(ULONG speed);
void MoveStep(LONG pulse);

#define DEBUG  //Debug on, if you want text message on the serial terminal
bool DEBUG_ON=true;
//#define USES4WIRE //For use with std. stepper library (Fl. Dam)
#define USES2WIRE //For use with MyStepper library (JMJK + OMJK + New SMJK)

#include "PrintFunc.h"

#ifdef USES4WIRE
#include <Stepper.h>
#endif
#ifdef USES2WIRE
#include "MyStepper.h"
#endif
#include <EEPROM.h>

//#define JERSLEV
//#define NYSKOV
//#define NYSKOV_NY
//#define NS_TEST
//#define JMJK
//#define JMJKTEST
#define OMJK

UWORD AnalogTrackData;
bool TurnIsActive=false;
bool HalfTurnAct=false;
bool SetupInitAct=false;
bool SetupInitStart=false;
bool SetupSaveAct=false;
bool StopOutOfPos=false;
UBYTE nTrackPos;
ULONG StepPos;
bool DistHalf=false;
DIRECTION direction;
bool DirectionAct;
bool direction_set=false;
TIME_T TimeSetup;
bool SetupMode=false;
bool MotorDirRev=false, MotorDirForw=false;
bool button_move_in_use=false;
bool button_half_in_use=false;
TIME_T MoveCancelTime;
bool MoveCancel=false;
bool ButtonIsHold=false;
TIME_T bhTime;
bool bhFirstTime=false;
ULONG accstep=0;
bool deaccel_act=false;
TIME_T LED_move_blink_time;
bool LED_move_stat;
char readstring[20];

#define BHFIRSTWAIT 200
#define BHWAIT 5

#ifdef JERSLEV
#include "jerslev.h"
#endif

#ifdef NYSKOV
#include "nyskov.h"
#endif

#ifdef NYSKOV_NY
#include "nyskovny.h"
#endif

#ifdef JMJK
#include "jmjk.h"
#endif

#ifdef JMJKTEST
#include "jmjktest.h"
#endif

#ifdef OMJK
#include "omjk.h"
#endif

const ULONG speedinit=STEPPERSTARTSP;
ULONG speedmax;

#ifndef TRACK_NO
#define TRACK_NO 5 //Default 5 tracks, if not defined in another place
#endif
#define MAX_V_VAL 1023 //Max value for analogRead at UNO, MEGA etc
UWORD lo[TRACK_NO]; // for analog reading min (low) value
UWORD hi[TRACK_NO]; // for analog reading max (high) value
//Everything between low and high value is a valid for an correct value

void setup()
{
#ifdef DEBUG
	Print_init();
#endif
	speedmax=STEPPERSPEEDSETUP;
#ifdef ONE_BUTTON_FOR_MOVE
	calc_index_init(); //activate calc_index_init if not using simple step by step movements
#endif
#ifdef ONE_PUSH_DIRECTION
	pinMode(pin_turn_direction,INPUT);
	pinMode(pin_LED_clockwise,OUTPUT);
	pinMode(pin_LED_counter_clockwise,OUTPUT);
#endif
#ifdef TWO_PUSH_DIRECTION
	pinMode(pin_turn_direction_forw,INPUT);
	pinMode(pin_turn_direction_backw,INPUT);
	pinMode(pin_setup_mode,INPUT);
#endif
#ifdef DRIVING_CURRENT
	pinMode(pin_dc_bit0,OUTPUT);
	pinMode(pin_dc_bit1,OUTPUT);
	pinMode(pin_dc_bit2,OUTPUT);
	pinMode(pin_dc_bit3,OUTPUT);
	pinMode(pin_dc_bit_active,OUTPUT);
	digitalWrite(pin_dc_bit0,LOW); //turn off bit 1 for driving current
	digitalWrite(pin_dc_bit1,LOW); //turn off bit 2 for driving current
	digitalWrite(pin_dc_bit2,LOW); //turn off bit 3 for driving current
	digitalWrite(pin_dc_bit3,LOW); //turn off bit 4 for driving current
	digitalWrite(pin_dc_bit_active,LOW); //turn off driving current
#endif
#ifdef ONE_BUTTON_FOR_MOVE
	pinMode(pin_turn_move,INPUT); //activate pin_turn_move and 
	pinMode(pin_selector,INPUT); //rotory selector if not using simple step by step movements
#endif
	pinMode(pin_half_turn,INPUT);
	pinMode(pin_zero_point,INPUT);
#ifdef SETUP_PINS
	pinMode(pin_setup_save,INPUT);
	pinMode(pin_setup_led,OUTPUT);
	digitalWrite(pin_setup_led,LOW); //turn off setup LED
#endif
#ifdef ONE_PUSH_DIRECTION
	digitalWrite(pin_LED_clockwise,HIGH); //turn on LED FORWARD
	digitalWrite(pin_LED_counter_clockwise,LOW); //turn off LED REVERSE
	direction=FORWARD;
	MotorDirForw=true;
	Println("Direction: FORWARD");
#endif
#ifdef PUSH_HALF_AS_START
	direction=FORWARD;
	MotorDirForw=true;
	Println("Direction: FORWARD");
#endif
#ifdef TWO_PUSH_DIRECTION
	DirectionAct=false;
	chk_button_direction();
	if(DirectionAct==false) //if still false
	{
		DirectionAct=true; //then set true
		chk_button_direction(); //and try again
	}
	if(direction==FORWARD)
	{
		MotorDirForw=true;
		MotorDirRev=false;
	}
	if(direction==REVERSE)
	{
		MotorDirForw=false;
		MotorDirRev=true;
	}
#endif
#ifdef LED_MOVE
	pinMode(pin_LED1_move,OUTPUT);
	pinMode(pin_LED2_move,OUTPUT);
#endif
	
	nTrackPos=0;
	StepPos=0;

	SetupMode=true; //set in setup mode for full speed at init
	Read_EEprom(TrackPos);

	if(digitalRead(pin_zero_point)==0) //if sensor can't be seen at startup, try to find it ...
	{
		if(reset_stepper()==false) //if sensor haven't been found after one full turn
		{
			Println("Sensor not found! ");
			alarm(); //go in alarm mode
		}
	}
	else //but if sensor are seen at startup, we have to move a bit, until undetected
	{
		ULONG x=0;
		do
		{
			stepper_move(1, REVERSE); //and sensor has to be detected forward moving, so go reverse
			x++;
			if(x>GearStepsPrTurn) //if max steps has been reached, something is wrong
				alarm();
		}
		while(digitalRead(pin_zero_point));  // do until sensor report open
		if(reset_stepper()==false) //after detected, we have to reset to hardware zero point
		{
			Println("Sensor not found! ");
			alarm(); //and if sensor not found afterward, go in alarm mode
		}
	}
	SetupMode=false; //now set mode back to normal after startup.
}

void loop()
{
#ifdef SETUP_PINS
	if(MAGICFILENUMBER!=0)
	{	
#ifdef TWO_PUSH_SETUP
		if(digitalRead(pin_turn_direction)&&digitalRead(pin_turn_move))
#endif
#ifdef ONE_PUSH_SETUP
		if(digitalRead(pin_setup_mode))
#endif
		{
			if(SetupInitAct==false)
			{
				SetupInitAct=true;
				SetupInitStart=true;
				TimeSetup=millis()+SETUPWAITTIME;
			}
			else
			{
				if(millis()>TimeSetup)
				{
					SetupMode=true;
					SetupInitStart=false;
					setup_routine();
				}
			}
		}
		else
		{
			SetupInitAct=false;
		}
	}
#endif

	chk_button_halfturn();
#if defined (ONE_BUTTON_FOR_MOVE)
	chk_button_direction(); //activate routine if not using simple step by step movements
#endif
#if defined (ONE_BUTTON_FOR_MOVE) || defined (TWO_BUTTON_FOR_MOVE)
	chk_button_move();
#endif
#ifdef DRIVING_CURRENT
	chk_driving_current();
#endif
}

void split_word(UWORD val, UBYTE *a, UBYTE *b)
{
	UWORD g;
	*a=val & 0xff;
	g=val & 0xff00;
	*b=g >> 8;
}

void split_long(ULONG val, UBYTE *a, UBYTE *b, UBYTE *c)
{
	ULONG g;
	*a=val & 0xff;
	g=val & 0x0000ff00;
	*b=g >> 8;
	g=val & 0x00ff0000;
	*c=g >> 16;
}

void join_word(UWORD *val, UBYTE a, UBYTE b)
{
	*val=a | (b << 8);
}

void join_long(ULONG *val, UBYTE a, UBYTE b, UBYTE c)
{
	*val=a + ((ULONG)b << 8) + ((ULONG)c << 16);
}

void Save_EEprom(ULONG *v)
{
	UWORD addr;
	UBYTE a, b, c;

	if(MAGICFILENUMBER==0) //if magic is zero, no save will be done
		return;
	addr=0;
	a=MAGICFILENUMBER;
	EEPROM.write(addr, MAGICFILENUMBER); //An 8 bit value saved for validating on read, that data exist
	Print("Saving to EEprom address ", addr);
	Println("value for Magicnumber: ",a);

	addr++;
	split_long(StepCorrect, &a, &b, &c);
	EEPROM.write(addr, a); //Value for turntable zero from the sensor zero - low byte.
	EEPROM.write(addr+1, b); //Value for turntable zero from the sensor zero - middle low byte.
	EEPROM.write(addr+2, c); //Value for turntable zero from the sensor zero - middle high byte.

	Print("Saving corrections value ");
	Print("to EEprom address ", addr);
	Print("to ", addr+2);
	Print("values: ",a);
	Print(" ",b);
	Print(" ",c);
	Println(" : total: ", StepCorrect);

	addr+=3;
	Print("Saving step corrections direction ");
	Print("to EEprom from address ", addr);
	Println("(1=REVERSE, 2=FORWARD): ",StepCorrectDir);
	
	EEPROM.write(addr, (UBYTE) StepCorrectDir); //Value for turntable direction from sensor zero.
	
	addr++;
	for(UBYTE x=0; x<TRACK_NO; x++)
	{
		split_long(v[x], &a, &b, &c);
		EEPROM.write(addr, a);
		EEPROM.write(addr+1, b);
		EEPROM.write(addr+2, c);
		Print("For track pos ",x);
		Print("saving to EEprom from address ", addr);
		Print("to ", addr+2);
		Print("values: ", a);
		Print(" ", b);
		Print(" ", c);
		Println(" : total: ", v[x]);
		addr+=3;
	}
}

void Read_EEprom(ULONG *v)
{
	UWORD addr;
	UBYTE a, b, c;

	if(MAGICFILENUMBER==0) //if magic is zero, no read will be done, using values from setup file
		return;
	addr=0;
	a=EEPROM.read(addr);
	Print("Loading from EEprom address ", addr);
	Println("value for Magicnumber: ",a);
	Println("Expected value for Magicnumber: ",MAGICFILENUMBER);

	if(a==MAGICFILENUMBER) //An 8 bit value for validating that data exist and is correct
	{
		Println("Found a match, now loading settings from EEprom ... ");
		addr++;
		a=EEPROM.read(addr); //Value for turntable zero from the sensor zero - low byte.
		b=EEPROM.read(addr+1); //Value for turntable zero from the sensor zero - low middle byte.
		c=EEPROM.read(addr+2); //Value for turntable zero from the sensor zero - high middle byte.
		join_long(&StepCorrect, a, b, c);
		Print("Corrections value ");
		Print("loading from EEprom address ", addr);
		Print("to ", addr+2);
		Print("values: ", a);
		Print(" ", b);
		Print(" ", c);
		Println(": total: ", StepCorrect);

		addr+=3;
		StepCorrectDir=(DIRECTION) EEPROM.read(addr); //Value for turntable direction from sensor zero.
		Print("Step correction direction ");
		Print("loading from EEprom address ", addr);
		Println("(1=REVERSE, 2=FORWARD): ",StepCorrectDir);

		addr++;
		for(UBYTE x=0; x<TRACK_NO; x++)
		{
			a=EEPROM.read(addr);
			b=EEPROM.read(addr+1);
			c=EEPROM.read(addr+2);
			
			join_long(&v[x], a, b, c);
			Print("For track pos ",x);
			Print("loading from EEprom address ", addr);
			Print("to ", addr+2);
			Print("values: ", a);
			Print(" ", b);
			Print(" ", c);
			Println(" : total: ", v[x]);
			addr+=3;
		}
		Println("Done.");
	}
	else
	{
		Println("Did not find Magicnumber, using internal defaults");
		return;  //If magic number compare fails, return and use default values in array of data
	}
}

void stepper_move(ULONG steps, DIRECTION dir)
{
	ULONG speedstepup,speedstepdown;
	ULONG timenext;

	if(steps==0) return;
	if(dir==NEUTRAL) 
		return;
	
	if(SetupMode) 
		speedmax=STEPPERSPEEDSETUP;
	else
		speedmax=STEPPERSPEED;
		
	SetSpeedStep(speedmax);

#ifdef DRIVING_CURRENT
	driving_current(OFF);
#endif

	if(dir==FORWARD&&MotorDirForw==false)
	{
		MotorDirForw=true;
		MotorDirRev=false;
		SetSpeedStep(STEPPERSTARTSP);
		for(WORD x=0; x<GEAR_BLUR; x++) //Cheap steppers can have blur in gear when shift from one direction to the other direction
		{
			MoveStep(1);
		}
	}
	if(dir==REVERSE&&MotorDirRev==false)
	{
		MotorDirRev=true;
		MotorDirForw=false;
		SetSpeedStep(STEPPERSTARTSP);
		for(WORD x=0; x<GEAR_BLUR; x++) //Cheap steppers can have blur in gear when shift from one direction to the other direction
		{
			MoveStep(-1);
		}
	}

	timenext=millis()+ACCELERATE_TIME;
	speedstepup=speedinit;
	speedstepdown=speedinit;
	accstep=0;
	bool fullspeed=false;

#ifdef LED_MOVE
	digitalWrite(pin_LED1_move,HIGH);
	digitalWrite(pin_LED2_move,HIGH);
#endif

	for(ULONG x=0; x<steps; x++)
	{
		if(fullspeed==false) //if fullspeed is false, is topspeed not reached yet
		{
			if(millis()>timenext) // if millis is bigger than timenext
			{
				timenext=millis()+ACCELERATE_TIME; //save new time using millis + wait ACCELERATE_TIME
				if(speedstepup<=speedmax) // if speedstepup is smaller than topspeed
				{
					speedstepup+=2; //count speedstepup up
					accstep=x; //accstep follows x until

					if(speedstepup==speedmax) //speedstepup is equal speedmax
					{
						speedstepdown=speedmax; //then speedstepdown is equal speedmax
						fullspeed=true; //and fullspeed sets true
					}
					SetSpeedStep(speedstepup);
				}
			}
		}

		if(x+accstep>steps) //if x+accstep is bigger than steps
		{
			if(deaccel_act==false) //and if deaccel_act is false
			{
				timenext=millis()+ACCELERATE_TIME; //set time
				deaccel_act=true; //set deaccel_act true
				fullspeed=true; //and fullspeed is also true, regardless speedmax was reached
				speedstepdown=speedstepup; //set speedstepdown equal speedstepup
			}
			if(millis()>timenext) //if time has gone
			{
				timenext=millis()+ACCELERATE_TIME; //set new time
				if(speedstepdown>speedinit) //if speedstepdown is bigger than speedinit
				{
					speedstepdown-=2; //count speedstepdown down
					SetSpeedStep(speedstepdown);
				}
			}
		}
		if(SetupMode==false) 
		{
#if defined (ONE_BUTTON_FOR_MOVE)
			chk_button_direction(); 
#endif
			if(chk_cancel_move())
			{
				StopOutOfPos=true;
				deaccel_act=false;
				MoveCancel=false; //MoveCancel can't reset it self after returning to here.
#ifdef LED_MOVE
				digitalWrite(pin_LED1_move,LOW);
				digitalWrite(pin_LED2_move,LOW);
#endif
				return; //Cancel move, so we return and skip moving
			}
		}
		if(dir==FORWARD)
		{
			MoveStep(1);
			if(StepPos==(GearStepsPrTurn-1)) //we have reach top
				StepPos=0;  //so set to zero
			else
				StepPos++;
		}
		if(dir==REVERSE)
		{
			MoveStep(-1);
			if(StepPos==0)
				StepPos=(GearStepsPrTurn - 1);
			else
				StepPos--;
		}
#ifdef LED_MOVE
		chk_led_move();
#endif
	}
#ifdef LED_MOVE
	digitalWrite(pin_LED1_move,LOW);
	digitalWrite(pin_LED2_move,LOW);
#endif
	if(StepPos>=GearStepsPrTurn/2)
		DistHalf=true;
	else
		DistHalf=false;
#ifdef FLIP
	if(DistHalf)
	{
		if(direction_set==false)
		{
			direction=REVERSE;
			Println("Direction: REVERSE");
			direction_set=true;
		}
	}
	else
	{
		if(direction_set==true)
		{
			direction=FORWARD;
			Println("Direction: FORWARD");
			direction_set=false;
		}
	}
#endif
	
	deaccel_act=false;
	StopOutOfPos=false;
	
#ifdef DRIVING_CURRENT
	if(direction&&SetupMode==false)
		driving_current(ON);
#endif
}

#ifdef ONE_BUTTON_FOR_MOVE
bool chk_cancel_move()
{
	if(digitalRead(pin_turn_move)||digitalRead(pin_half_turn))//if not using simple step by step movements use this routine
	{
		if(MoveCancel==false)
		{
			MoveCancel=true;
			button_move_in_use=true;
			MoveCancelTime=millis()+CANCELMOVETIME; //Wait/hold botton this amount of millis to cancel move
		}
		else
		{
			if(millis()>MoveCancelTime) //And when the time is up
			{
				return true;   //return true to stop steppper move
			}
		}
	}
	else
	{
		if(MoveCancel==true)
			MoveCancel=false;
	}
	return false;
}
#endif

#ifdef TWO_BUTTON_FOR_MOVE
bool chk_cancel_move()
{
	if(digitalRead(pin_turn_direction_forw)||digitalRead(pin_turn_direction_backw))// else use this routine
	{
		if(MoveCancel==false)
		{
			MoveCancel=true;
			button_move_in_use=true;
			MoveCancelTime=millis()+CANCELMOVETIME; //Wait/hold botton this amount of millis to cancel move
		}
		else
		{
			if(millis()>MoveCancelTime) //And when the time is up
			{
				return true;   //return true to stop steppper move
			}
		}
	}
	else
	{
		if(MoveCancel==true)
			MoveCancel=false;
	}
	return false;
}
#endif

#ifdef PUSH_HALF_AS_START
bool chk_cancel_move()
{
	if(digitalRead(pin_half_turn))
	{
		if(MoveCancel==false)
		{
			MoveCancel=true;
			button_half_in_use=true;
			MoveCancelTime=millis()+CANCELMOVETIME; //Wait/hold botton this amount of millis to cancel move
		}
		else
		{
			if(millis()>MoveCancelTime) //And when the time is up
			{
				return true;   //return true to stop steppper move
			}
		}
	}
	else
	{
		if(MoveCancel==true)
			MoveCancel=false;
	}
	return false;
}
#endif

void calc_move(int new_pos, DIRECTION dir)
{
	ULONG count=0;

	if(dir==FORWARD) //if rotating is forward (clockwise)
	{
		if(StepPos>TrackPos[new_pos]) //then if current stepper pos is greater than new track pos
			count=(GearStepsPrTurn-StepPos)+TrackPos[new_pos]; //the count is max step minus stepper pos plus new track pos
		else
			count=TrackPos[new_pos]-StepPos; //else count is new track pos minus current stepper pos
	}
	if(dir==REVERSE) //if rotating is backward (counter-clockwise)
	{
		if(StepPos<TrackPos[new_pos]) //then if current stepper pos is lesser than new track pos
			count=(GearStepsPrTurn-TrackPos[new_pos])+StepPos; //the count is max step minus new track pos plus current stepper pos
		else
			count=StepPos-TrackPos[new_pos]; //else count is current stepper pos minus new track pos
	}
	if(count >= (GearStepsPrTurn/2)) //if count is greater or equal to max step diveded by 2
		count=count-(GearStepsPrTurn/2); //then count is cut down with half the steps max, thereby take the shortest turn
	
	if(count==0)
		Println("No moving, count is 0");
	else
	{
		Println("New track pos ", new_pos);
		Println("Step count to move ", count);
		Println("Stepper pos before ", StepPos);
		stepper_move(count, dir);
		Println("Stepper pos after ", StepPos);
		Println();
	}
}

#ifdef TWO_PUSH_DIRECTION 
void chk_button_direction() 
{
	int forw, backw;
	if(SetupInitStart)
		return; //We try to come in prog mode, return

	forw=digitalRead(pin_turn_direction_forw);
	backw=digitalRead(pin_turn_direction_backw);
	
	if(DirectionAct==false)
	{
		if(forw==1&&backw==0)
		{
			direction=FORWARD;
			Println("Direction: FORWARD");
			DirectionAct=true;
		}
		if(forw==0&&backw==1)
		{
			direction=REVERSE;
			Println("Direction: REVERSE");
			DirectionAct=true;
		}
	}
	if(DirectionAct==true)
	{
		if(forw==0&&backw==0)
		{
			direction=NEUTRAL;
			Println("Direction: NEUTRAL");
			DirectionAct=false;
		}
		if(forw==1&&backw==1)
		{
			direction=BOTH_DIRECTION;
			Println("Direction: BOTH DIRECTION active");
			DirectionAct=false;
		}
	}
}
#endif

#ifdef ONE_PUSH_DIRECTION
void chk_button_direction()
{
	if(SetupInitStart)
		return; //We try to come in prog mode, return
	if(digitalRead(pin_turn_direction))
	{
		if(DirectionAct==false)
		{
			DirectionAct=true;
			if(direction==FORWARD)
			{
				direction=REVERSE;
				digitalWrite(pin_LED_counter_clockwise, HIGH);
				digitalWrite(pin_LED_clockwise, LOW);
				Println("Direction: REVERSE");
			}
			else
			{
				direction=FORWARD;
				digitalWrite(pin_LED_clockwise, HIGH);
				digitalWrite(pin_LED_counter_clockwise, LOW);
				Println("Direction: FORWARD");
			}
		}
	}
	else
	{
		DirectionAct=false;
	}
}
#endif

#ifdef ONE_BUTTON_FOR_MOVE
void chk_button_move() 
{
	if(SetupInitStart)
		return; //We try to come in prog mode, return
	
	if(button_move_in_use)
		if(!(digitalRead(pin_turn_move)))
			button_move_in_use=false;

	if(button_move_in_use)
		return;
	
	if(digitalRead(pin_turn_move))
	{
		if(TurnIsActive==false)
		{
			TurnIsActive=true;
			if(SetupMode)
			{
				stepper_move(1, direction);
			}
			else
			{
				if(direction == FORWARD||direction == REVERSE)
				{
					AnalogTrackData=analogRead(pin_selector);
					nTrackPos=calc_index(AnalogTrackData);
					calc_move(nTrackPos, direction);
				}
				if(direction == NEUTRAL)
					Println("Direction neutral, can't move ");
				if(direction == BOTH_DIRECTION)
					Println("Direction set to both ways, can't move ");
			}
		}
	}
	else
	{
		if(TurnIsActive==true)
		{
			TurnIsActive=false;
		}
	}
}
#endif

#ifdef TWO_BUTTON_FOR_MOVE
void chk_button_move()
{
	if(SetupInitStart)
		return; //We try to come in prog mode, return
		
	if(button_move_in_use)
		if(!(digitalRead(pin_turn_direction_forw)||digitalRead(pin_turn_direction_backw)))
			button_move_in_use=false;

	if(button_move_in_use)
		return;
		
	if(digitalRead(pin_turn_direction_forw)||digitalRead(pin_turn_direction_backw))
	{
		if(SetupMode)
		{
			if(TurnIsActive==false) //if TurnIsActive are false
			{
				TurnIsActive=true; //set TurnIsActive true, used for setup only
				stepper_move(1, direction); //and we move one step
			}
		}
		else
		{
			if(digitalRead(pin_turn_direction_forw)==1&&digitalRead(pin_turn_direction_backw)==0)
			{
				direction=FORWARD;
				if(nTrackPos==TRACK_NO-1)
					nTrackPos=0;
				else
					nTrackPos++;
			}
			if(digitalRead(pin_turn_direction_forw)==0&&digitalRead(pin_turn_direction_backw)==1)
			{
				direction=REVERSE;
				if(nTrackPos==0)
					nTrackPos=TRACK_NO-1;
				else
					nTrackPos--;
			}
			if(digitalRead(pin_turn_direction_forw)==1&&digitalRead(pin_turn_direction_backw)==1) 
				return;
			calc_move(nTrackPos, direction);
		}

		if(TurnIsActive) //if TurnIsActive, we are in setupmode
		{
			if(ButtonIsHold==false) //and if ButtonIsHold are false
			{
				ButtonIsHold=true; //set ButtonIsHold true
				if(bhFirstTime==false) //if it is first time ButtonIsHold is true
				{
					bhTime=millis()+BHFIRSTWAIT; //use BHFIRSTWAIT as time delay (long delay)
					bhFirstTime=true; //and set bhFirstTime true
				}
				else
					bhTime=millis()+BHWAIT; //and else use BHWAIT as time delay (short delay)
			}
		}
		if(TurnIsActive&&ButtonIsHold) //if TurnIsActive and ButtonIsHold is true
		{
			if(bhTime<millis()) //and bhTime is < than the time now
			{
				TurnIsActive=false; //then TurnIsActive must be set to false
				ButtonIsHold=false; //and likewise for ButtonIsHold
				if(digitalRead(pin_half_turn)) //if half turn is activated at same time
					stepper_move(10, direction); //we move ten steps at a time
				else
					stepper_move(1, direction); //otherwise we move only one step at a time
			}
		}
	}
	else //No pins for buttons is pressed
	{
		if(TurnIsActive==true) //and if TurnIsActive has been true
		{
			TurnIsActive=false; //now set all below false for cleanup before use the next time
			ButtonIsHold=false;
			bhFirstTime=false;
			Println("StepPos : ",StepPos);
		}
	}
}
#endif

void chk_button_halfturn()
{
	if(button_half_in_use)
		if(!(digitalRead(pin_half_turn)))
			button_half_in_use=false;

	if(button_half_in_use)
		return;
	
	if(digitalRead(pin_half_turn))
	{
		if(HalfTurnAct==false)
		{
			HalfTurnAct=true;
			if(SetupMode)
			{
				stepper_move(HIGHSTEP, direction);
			}
			else
			{
				if(StopOutOfPos)
				{
					StopOutOfPos=false;
					calc_move(nTrackPos, direction);
				}
				else
				{
					Println("Turn 180 degrees");
					stepper_move(GearStepsPrTurn / 2, direction);
					Println("Stepper pos ", StepPos);
					Println();
				}
			}
		}
	}
	else
	{
		if(HalfTurnAct==true)
		{
			HalfTurnAct=false;
		}
	}
}

#ifdef SETUP_PINS
bool chk_button_save_pos(int x)
{
#ifdef PUSH_NORMALY_CLOSED
	if(digitalRead(pin_setup_save)==false) //If button is a NC
#endif
#ifdef PUSH_NORMALY_OPEN
	if(digitalRead(pin_setup_save)) //If button is a NO
#endif
	{
		if(SetupSaveAct==false)
		{
			SetupSaveAct=true;
			TrackPos[x]=StepPos;
			Println("Track steps saved for ", x);
			Println("Step pos ", TrackPos[x]);
			return false;
		}
	}
	else
	{
		SetupSaveAct=false;
	}
	return true;
}
#endif

#ifdef SETUP_PINS
bool read_save_pos_correction(ULONG x)
{
#ifdef PUSH_NORMALY_CLOSED
	if(digitalRead(pin_setup_save)==false) //If button is a NC
#endif
#ifdef PUSH_NORMALY_OPEN
	if(digitalRead(pin_setup_save)) //If button is a NO
#endif
	{
		if(SetupSaveAct==false)
		{
			SetupSaveAct=true;
			StepCorrect=x;
			StepCorrectDir=direction;
			Println("Step pos correction ", x  );
			Println("Stepper position ", StepPos);
			return false;
		}
	}
	else
	{
		SetupSaveAct=false;
	}
	return true;
}
#endif

bool reset_stepper()
{
	bool found=false;

#ifdef DRIVING_CURRENT
	driving_current(OFF);
#endif

	Println("Trying to find sensor ... ");
	for(ULONG x=0; x<GearStepsPrTurn; x++)
	{
		stepper_move(1, FORWARD);
		if(digitalRead(pin_zero_point)) //Found sensor zero point
		{
			Println("Found it ");
			found=true;
			if(StepCorrect)
			{
				Println("Now moving the stepper to correct stepper correction : ",StepCorrect);
				stepper_move(StepCorrect, StepCorrectDir);
			}
			Println("StepPos now, before reset ",StepPos);
			StepPos=0; //after step correction set, reset stepper position
			break;
		}
	}
	if(found)
	{
#ifdef ONE_BUTTON_FOR_MOVE //if NOT def two push-button for simple step by step movements
		UWORD tmp_track_select=analogRead(pin_selector); //use this in code
		nTrackPos=calc_index(tmp_track_select);
#endif
#ifdef TWO_BUTTON_FOR_MOVE
		nTrackPos=0;
#endif
		calc_move(nTrackPos, FORWARD);
		Println("New track pos after startup ", nTrackPos);
		Println("Stepper pos after startup ", StepPos);
	}
	return (found);
}

void alarm()
{
	Println("Shutting down ... ");
	while (1)
	{
#ifdef TWO_LED_DIRECTION
		digitalWrite(pin_LED_clockwise, HIGH);
		digitalWrite(pin_LED_counter_clockwise, LOW);
		delay(300);
		digitalWrite(pin_LED_counter_clockwise, HIGH);
		digitalWrite(pin_LED_clockwise, LOW);
		delay(300);
#endif
#ifdef SETUP_PINS
		digitalWrite(pin_setup_led, HIGH);
		delay(300);
		digitalWrite(pin_setup_led, LOW);
		delay(300);
#endif
	}
}

#ifdef SETUP_PINS
void setup_routine()
{
	if(MAGICFILENUMBER==0) return;
	
	UBYTE y;
	ULONG x=0;

	Println("Now in programming mode ");
	digitalWrite(pin_setup_led, HIGH);

	Println("Looking after the zero pos sensor ... ");
	if(digitalRead(pin_zero_point)) //sensor detectet
	{
		x=0;
		do
		{
			stepper_move(1, REVERSE);
			x++;
			if(x > GearStepsPrTurn)
				alarm(); //If sensor reading dosn't break before max steps, set alarm
		}
		while (digitalRead(pin_zero_point));  //move backward until sensor reading break the signal
	}

	bool found=false;
	for(x=0; x<GearStepsPrTurn; x++)
	{
		if(digitalRead(pin_zero_point)) //we found sensor zero point
		{
			StepPos=0; //so reset stepper value
			found=true;
			break;
		}
		else
		{
			stepper_move(1, FORWARD);
		}
	}
	if(found)
	{
		Println("Zero sensor found ");
		Println("Set turntable track zero compared to sensor zero");
	}
	else
		alarm();
	y=0;
	do //set and save turntable zero point from sensor zero point
	{
		chk_button_halfturn(); //step 10 steps per push
#ifdef ONE_BUTTON_FOR_MOVE 
		chk_button_direction();  
#endif
		chk_button_move();   //step 1 step per push
		y=read_save_pos_correction(StepPos);    //save value of StepPos in StepCorrect
	}
	while (y);
	Println("Zero point saved ");
	StepPos=0; //and reset StepPos

	y=0;

	x=0;
	
	TrackPos[0]=StepPos;
	Print("Steps saved for track ", x);
	Println(" value for steps ",TrackPos[x] );
	
	for(x=1; x<TRACK_NO; x++)
	{
		Println("Now set steps for track ",x);
		do
		{
			chk_button_halfturn(); //step 10 steps per push
#ifdef ONE_BUTTON_FOR_MOVE 
			chk_button_direction(); 
#endif
			chk_button_move();   //step 1 step per push
			y=chk_button_save_pos(x); //save value of StepPos in track pos
		}
		while (y);							//Continue loop until y gets false
		Print("Steps saved for track ", x);
		Println(" value for steps ",TrackPos[x] );
	}

	Save_EEprom(TrackPos); //now save all values in eeprom

	SetupMode=true; //set in setup mode to have full speed in SetupMode
	Read_EEprom(TrackPos);
	if(digitalRead(pin_zero_point)==0) //if sensor can't be seen at startup, then find sensor pos by turning turntable
	{
		if(reset_stepper()==false) //and if sensor hasn't been found after one full turn
		{
			Println("Sensor not found! ");
			alarm(); //go in alarm mode
		}
	}
	else //but if sensor is active at startup, make a reverse move until no longer active
	{
		ULONG x=0;
		do
		{
			stepper_move(1, REVERSE);
			x++;
			if(x>GearStepsPrTurn)
				alarm();
		}
		while(digitalRead(pin_zero_point));
		if(reset_stepper()==false) //and if sensor hasn't been found after one full turn
		{
			Println("Sensor not found! ");
			alarm(); //go in alarm mode
		}
	}

	Println("Now out of programming mode");
	digitalWrite(pin_setup_led, LOW);
	SetupMode=false;
}
#endif

UBYTE calc_index(UWORD val)
{
	UBYTE x,y=0;
	for(x=0; x<TRACK_NO; x++)
	{
		if (val >= lo[x]&&val <= hi[x])
		{
			y=x;
			break;
		}
	}
	return (y);
}

void calc_index_init()
{
	UBYTE x;
	UBYTE max_index=TRACK_NO-1; //number of track index minus one
	float sum=0.0;
	float offset_val=((float)(MAX_V_VAL+1) / (float)max_index) / 2; //value in fluctuation from center value
	float range_val=(float)(MAX_V_VAL+1) / (float)max_index; //size a range covers

	lo[0]=0;
	hi[0]=offset_val; //middle of range
	sum=offset_val; //sum starts with middle range

#ifdef DEBUG
	Print("Index goes from 0 to ", max_index);
	Print(" - Mid range Val ", (float)offset_val);
	Println(" - Range span Val ", (float)range_val);
#endif

	for(x=1; x < max_index; x++)
	{
		lo[x]=sum+1; //low x is sum + 1 higher
		sum=sum+range_val; //new sum is sum + range_val
		hi[x]=sum; //and high x is this sum
	}
	lo[max_index]=sum+1; 
	hi[max_index]=MAX_V_VAL;

#ifdef DEBUG
	for(x=0; x<TRACK_NO; x++)
	{
		Print("Index ", x);
		Print("span from ", lo[x]);
		Println("to ", hi[x]);
	}
#endif
}

#ifdef LED_MOVE
void chk_led_move()
{
	if(millis()>LED_move_blink_time)
	{
		LED_move_blink_time=millis()+LED_MOVE_BLINK_TIME;
		LED_move_stat=!LED_move_stat;
		digitalWrite(pin_LED1_move,LED_move_stat);
		digitalWrite(pin_LED2_move,LED_move_stat);
	}
}
#endif		
		
void SetSpeedStep(ULONG speed)
{
#ifdef USES4WIRE
	myStepper.setSpeed(speed);
#endif
#ifdef USES2WIRE
	myStepper.SetSpeed(speed);
#endif
}

void MoveStep(LONG pulse)
{
#ifdef USES4WIRE
	myStepper.step(pulse);
#endif
#ifdef USES2WIRE
	myStepper.Steps(pulse);
#endif
}
