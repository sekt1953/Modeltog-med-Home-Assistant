//Include for print routines
//Version 20230305

#include <Arduino.h>
#ifndef __Print_func
#define __Print_func
#endif

void Print_init();
void Print(const char *txt);
void Print(const char *txt, float var);
void Print(const char *txt, signed long var);
void Print(const char *txt, unsigned long var);
void Print(const char *txt, signed int var);
void Print(const char *txt, unsigned int var);
void Print(const char *txt, unsigned char var);
void Println();
void Println(const char *txt);
void Println(const char *txt, float var);
void Println(const char *txt, signed long var);
void Println(const char *txt, unsigned long var);
void Println(const char *txt, signed int var);
void Println(const char *txt, unsigned int var);
void Println(const char *txt, unsigned char var);
void Println(signed long var);
void Println(unsigned long var);
void Println(signed int var);
void Println(unsigned int var);
void Println(unsigned char var);
