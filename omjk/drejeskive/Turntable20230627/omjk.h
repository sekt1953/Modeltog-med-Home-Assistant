//definitions for OMJK turntable on JMJK layout
//Version 20230519

#ifndef OMJK
#define OMJK
#endif

/*
Pins for OMJK turntable:
2 til 3=stepper motor driver
4=sensor zero point
5=LED for turntable is moving
9=button 1 and 2 for start/stop turntable rotating
*/

#define HIGHSTEP 10 //stepper value for button half a turn in setup mode
#define SETUPWAITTIME 5000 //wait time in milli seconds for activeting setup mode
#define CANCELMOVETIME 500 //wait time in milli seconds for cancel an active move
#define MAGICFILENUMBER 0 //Unik number for save in EEprom, that must match when read back, zero for no use
#define PUSH_HALF_AS_START
#define PUSH_NORMALY_OPEN
#define LED_MOVE
#define LED_MOVE_BLINK_TIME 250
#define STEPPERSPEED 150 //speed max for stepper motor
#define STEPPERSPEEDSETUP 150 //speed max for stepper motor in setup
#define STEPPERSTARTSP 15 //speed for motor start
#define ACCELERATE_TIME 5 //time between update for acceleration in milli seconds
#define STEP_UP_VAL 2 //step values for acceleration of stepper motor
#define GEAR_BLUR 0 //corrections value for slup in stepper gear
#define FLIP //turntable flips forward/reverse automatic for each turn

const int MotorStepsPrTurn=200; //steps for steppermotor one turn
const ULONG GearStepsPrTurn=21332; //steps for turntable one turn
const int pin_zero_point=4;
const int pin_half_turn=12;
const int pin_LED1_move=8;
const int pin_LED2_move=9;

MyStepper myStepper(MotorStepsPrTurn, 2, 3, 13); //initialize stepper on pins 2 to 3
//myStepper(Rotation pr turn, STEP_PIN, DIR_PIN, EN_PIN)

#define TRACK_NO 1
ULONG TrackPos[TRACK_NO]={0}; //default values for track pos
DIRECTION StepCorrectDir=FORWARD; //direction from sensor to track zero 
ULONG StepCorrect=1133; //number of steps from sensor til track zero
