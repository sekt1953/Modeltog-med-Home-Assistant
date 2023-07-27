//definitions for Nyskov turntable on SMJK layout
//Version 20230526

#ifndef NYSKOV_NY 
#define NYSKOV_NY
#endif

/*
Pins for Nyskov turntable:
2 til 4=stepper motor driver
5 LED for turntable moving
6=sensor zero point
7=button for setup mode
8 to 12=bits for controlling PCB card for driving current
13=LED for setup mode
A0=selector with resistor for track position
A1=button for direction forward
A2=button for direction reverse
A3=button for start turntable rotating
A4=button for turntable make half a turn
A5=button for save pos in setup mode
Activate of setup is done holding button 'setup mode' in SETUPWAITTIME milli seconds
*/

#define HIGHSTEP 10 //stepper value for button half a turn in setup mode
#define SETUPWAITTIME 5000 //wait time in milli seconds for activeting setup mode
#define CANCELMOVETIME 1500 //wait time in milli seconds for cancel an active move
#define MAGICFILENUMBER 159 //Unik number for save in EEprom, that must match when read back, zero for no use
#define TWO_PUSH_DIRECTION
#define ONE_PUSH_SETUP
#define ONE_BUTTON_FOR_MOVE //
#define SETUP_PINS
#define PUSH_NORMALY_OPEN
#define DRIVING_CURRENT
#define STEPPERSPEED 150 //speed for stepper motor
#define STEPPERSPEEDSETUP 150 //speed max for stepper motor in setup
#define STEPPERSTARTSP 10 //speed for motor start
#define ACCELERATE_TIME 20 //time between update for acceleration in milli seconds
#define STEP_UP_VAL 1 //step values for acceleration of stepper motor
#define GEAR_BLUR 0 //corrections value for slup in stepper gear
#define LED_MOVE
#define LED_MOVE_BLINK_TIME 250
const int MotorStepsPrTurn=200; //steps for steppermotor one turn
const int GearStepsPrTurn=19200; //steps for turntable one turn

const int pin_zero_point=6;
const int pin_setup_mode=7;
#ifdef DRIVING_CURRENT
const int pin_dc_bit0=8;
const int pin_dc_bit1=9;
const int pin_dc_bit2=10;
const int pin_dc_bit3=11;
const int pin_dc_bit_active=12;
UBYTE dc_bit_active;
bool driving_curr=false;
#endif
const int pin_setup_led=13;
const int pin_selector=A0;
#ifdef TWO_PUSH_DIRECTION
const int pin_turn_direction_forw=A1;
const int pin_turn_direction_backw=A2;
#endif
const int pin_turn_move=A3;
const int pin_half_turn=A4;
const int pin_setup_save=A5;
const int pin_LED1_move=5;
const int pin_LED2_move=5;

MyStepper myStepper(MotorStepsPrTurn, 2, 3, 4); //initialize stepper on pins 2 to 4
//myStepper(Rotation pr turn, STEP_PIN, DIR_PIN, EN_PIN)


#define TRACK_NO 11
ULONG TrackPos[TRACK_NO]={0,5152,5704,6272,6856,7424,7960,8512,9064,9600,10192}; //default values for track pos
DIRECTION StepCorrectDir=FORWARD; //direction from sensor to track zero 
ULONG StepCorrect=104; //number of steps from sensor til track zero

#ifdef DRIVING_CURRENT
#ifndef DCURRENT_H
#include "dcurrent.h"
#endif
#endif
