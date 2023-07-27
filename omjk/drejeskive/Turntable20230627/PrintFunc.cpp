//Print routines
//Version 20230305

#ifndef __Print_func
#include "PrintFunc.h"
#endif

extern bool DEBUG_ON;

void Print_init()
{
	Serial.begin(115200); 
}

void Print(const char *txt)
{
   if(DEBUG_ON)
   {
   	String text=txt;
   	Serial.print(text);
   }
   else
	   return;
}

void Print(const char *txt, signed long var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.print(var);
  		Serial.print(" ");
  	}
  	else
	  	return;
}

void Print(const char *txt, float var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.print((float)var);
  		Serial.print(" ");
  	}
  	else
	  	return;
}

void Print(const char *txt, unsigned long var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.print(var);
  		Serial.print(" ");
  	}
  	else
	  	return;
}

void Print(const char *txt, unsigned int var)
{
	Print(txt, (unsigned long) var);
}

void Print(const char *txt, signed int var)
{
	Print(txt, (signed long) var);
}

void Print(const char *txt, unsigned char var)
{
	Print(txt, (signed int) var);
}

void Println()
{
  	if(DEBUG_ON)
  	{
  		Serial.println();
  	}
  	else
	  	return;
}

void Println(const char *txt)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.println(text);
  	}
  	else
	  	return;
}

void Println(const char *txt, float var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.println(var);
  	}
  	else
	  	return;
}

void Println(const char *txt, signed long var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.println(var);
  	}
  	else
	  	return;
}

void Println(const char *txt, unsigned long var)
{
  	if(DEBUG_ON)
  	{
  		String text=txt;
  		Serial.print(text);
  		Serial.println(var);
  	}
  	else
	  	return;
}

void Println(const char *txt, signed int var)
{
	Println(txt, (signed long) var);
}

void Println(const char *txt, unsigned int var)
{
	Println(txt, (unsigned long) var);
}

void Println(const char *txt, unsigned char var)
{
	Println(txt, (signed int) var);
}

void Println(signed long var)
{
  	if(DEBUG_ON)
  	{
  		Serial.println(var);
  	}
  	else
	  	return;
}

void Println(unsigned long var)
{
  	if(DEBUG_ON)
  	{
  		Serial.println(var);
  	}
  	else
	  	return;
}

void Println(signed int var)
{
	Println((signed long) var);
}

void Println(unsigned int var)
{
	Println((unsigned long) var);
}

void Println(unsigned char var)
{
	Println((unsigned long) var);
}
