//definitions for JMJK turntable on JMJK layout
//Version 20230526

#ifndef JMJKTEST
#define JMJKTEST
#endif

/*
Pins for JMJK turntable:
2 til 3=stepper motor driver
4=sensor zero point
5=button for setup mode
6=button for direction forward - must be a toggle switch between forward and reverse
7=button for direction reverse - must be a toggle switch between forward and reverse
8=button for start turntable rotating
9=button for turntable make half a turn
10=button for save pos in setup mode
13=LED for setup mode
A0=selector with resistor for track position
Activate of setup is done holding button 'setup mode' in SETUPWAITTIME milli seconds
*/

#define HIGHSTEP 10 //stepper value for button half a turn in setup mode
#define SETUPWAITTIME 5000 //wait time in milli seconds for activeting setup mode
#define CANCELMOVETIME 1500 //wait time in milli seconds for cancel an active move
#define MAGICFILENUMBER 0 //Unik number for save in EEprom, that must match when read back, zero for no use
#define TWO_PUSH_DIRECTION
#define ONE_PUSH_SETUP
#define ONE_BUTTON_FOR_MOVE //
#define SETUP_PINS
#define PUSH_NORMALY_OPEN
#define STEPPERSPEED 500 //speed max for stepper motor
#define STEPPERSPEEDSETUP 300 //speed max for stepper motor in setup
#define STEPPERSTARTSP 15 //speed for motor start
#define ACCELERATE_TIME 5 //time between update for acceleration in milli sec
#define STEP_UP_VAL 2 //step values for acceleration of stepper motor
#define GEAR_BLUR 0 //corrections value for slup in stepper gear
#define LED_MOVE
#define LED_MOVE_BLINK_TIME 250
const int MotorStepsPrTurn=200; //steps for steppermotor one turn
const ULONG GearStepsPrTurn=80000; //steps for turntable one turn

const int pin_zero_point=4;
const int pin_setup_mode=5;
const int pin_setup_led=13;
const int pin_selector=A0;
#ifdef TWO_PUSH_DIRECTION
const int pin_turn_direction_forw=6;
const int pin_turn_direction_backw=7;
#endif
const int pin_turn_move=8;
const int pin_half_turn=9;
const int pin_setup_save=10;
const int pin_LED1_move=13;
const int pin_LED2_move=13;


MyStepper myStepper(MotorStepsPrTurn, 2, 3, 11); //initialize stepper on pins 2 to 3
//myStepper(Rotation pr turn, STEP_PIN, DIR_PIN, EN_PIN)

#define TRACK_NO 10
ULONG TrackPos[TRACK_NO]=
{
	    0, 4000, 8000,
	12000,16000,20000,
	24000,28000,32000,
	36000
}; //default values for track pos

DIRECTION StepCorrectDir=FORWARD; //direction from sensor to track zero 
ULONG StepCorrect=1133; //number of steps from sensor til track zero
