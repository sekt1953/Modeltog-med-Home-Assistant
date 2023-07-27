//definitioner for Jerslev turntable on Flemmings layout
//Version 20230206

#ifndef JERSLEV 
#define JERSLEV
#endif

/*
Pins for Flemming Dams turntable
2=button for direction change
3=button for start turntable rotating
4=button for turntable make half a turn
5=sensor zero point
6=LED for turning clockwise
7=LED for turning counter-clockwise 
8 til 11=stepper motor driver
12=button for save pos in setup mode
13=LED for setup mode
A0=selector with resistor for track position
Activate of setup is done holding button 'start rotating' and button 'direction change' in SETUPWAITTIME milli seconds
*/

#define HIGHSTEP 10 //stepper value for button half a turn in setup mode
#define SETUPWAITTIME 5000 //wait time in milli seconds for activeting setup mode
#define CANCELMOVETIME 1500 //wait time in milli seconds for cancel an active move
#define STEPPERSPEED 80 //speed for stepper motor
#define STEPPERSPEEDSETUP 40 //speed max for stepper motor in setup
#define STEPPERSTARTSP 20 //speed for motor start
#define ACCELERATE_TIME 5 //time between update for acceleration in milli seconds
#define STEP_UP_VAL 5 //step values for acceleration of stepper motor
#define GEAR_BLUR 23 //corrections value for slup in stepper gear
#define MAGICFILENUMBER 129 //Unik number for save in static ram, that must match when read back
#define ONE_PUSH_DIRECTION
#define ONE_BUTTON_FOR_MOVE //
#define PUSH_NORMALY_CLOSED
#define TWO_PUSH_SETUP
#define TWO_LED_DIRECTION
#define SETUP_PINS

const int MotorStepsPrTurn=64;  //steps for steppermotor one turn
const int GearStepsPrTurn=4096; //steps for turntable one turn
const int pin_turn_direction=2;
const int pin_turn_move=3;
const int pin_half_turn=4;
const int pin_zero_point=5;
#ifdef TWO_LED_DIRECTION
const int pin_LED_clockwise=6;
const int pin_LED_counter_clockwise=7;
#endif
const int pin_setup_save=12;
const int pin_setup_led=13;
const int pin_selector=A0;

Stepper myStepper(MotorStepsPrTurn, 8, 9, 10, 11); //initialize stepper on pins 8 to 11

#define TRACK_NO 5
ULONG TrackPos[TRACK_NO]={0,500,700,900,1100};  //default values for track pos
DIRECTION StepCorrectDir=FORWARD; //direction from sensor to track zero 
ULONG StepCorrect=0; //number of steps from sensor til track zero
