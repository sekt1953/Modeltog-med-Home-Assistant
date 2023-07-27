//Routines for controlling driving current for turntable with stepper motor.
//Version 20230528

#ifndef DCURRENT_H
#define DCURRENT_H
#endif

void driving_current(UBYTE akt);
void chk_driving_current();

bool dc_state=false;

void driving_current(UBYTE akt)
{
  	UBYTE dc_bit0,dc_bit1,dc_bit2,dc_bit3;
  
  	if(akt)
  	{
    	if(dc_state==false)
    	{
    		dc_state=true;
    		if(direction)
    		{
      		dc_bit0=nTrackPos&1;
      		dc_bit1=nTrackPos&2;
      		dc_bit2=nTrackPos&4;
      		dc_bit3=nTrackPos&8;
      		digitalWrite(pin_dc_bit0,dc_bit0);
      		digitalWrite(pin_dc_bit1,dc_bit1);
      		digitalWrite(pin_dc_bit2,dc_bit2);
      		digitalWrite(pin_dc_bit3,dc_bit3);
      		digitalWrite(pin_dc_bit_active,HIGH);
      		Println("Driving current on for track ",nTrackPos);
    		}
    	}
  	}
  	else
  	{
  		if(dc_state==true)
  		{
  			dc_state=false;
	    	digitalWrite(pin_dc_bit_active,LOW);
   	 	Println("Driving current off "); 
   	}
  	} 
}

void chk_driving_current()
{
  	if(SetupMode&&driving_curr)
  	{
    	driving_curr=false;
    	driving_current(OFF);
    	return;
  	}
  	if(SetupMode)
    	return;
    
  	if(direction)
  	{
    	if(driving_curr==false)
    	{
      	driving_curr=true;
      	driving_current(ON);
    	}
  	}
  	else
  	{
    	if(driving_curr)
    	{
      	driving_curr=false;
      	driving_current(OFF);
    	}
  	}
}
