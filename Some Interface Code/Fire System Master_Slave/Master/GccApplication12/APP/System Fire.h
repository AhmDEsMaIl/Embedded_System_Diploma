/*
 * System_Fire.h
 *
 * Created: 3/1/2023 2:21:53 AM
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#include "LED.h"
#include "Servo_Motor.h"
#include "Buzzer.h"
#include "RGB.h"
#ifndef SYSTEM FIRE_H_
#define SYSTEM FIRE_H_
#define  Number_OF_TASKS     10
#define  ARRAY1_SIZE         20
#define  Number_OF_CON       10
#define  ARRAY2_SIZE         20

typedef struct
{
	u8 *str;
	void(*fptr)(u32 num);
}TASKS_t;

typedef struct
{
	u8 *str;
	void(*fptr)(Colors C1,Colors C2);
}RGB_t;

u8 check_string(u8 *Urat_str);									
void Split_String_Tasks(u8 *New_Str, u8 *num);
void Turn_ON_Task(u8 *New_Str, u8 num);


void Split_String_RGB(u8 *first_Str, u8 *second_str);
void Turn_ON_RGB(u8 *New_Str, u8 num);


#endif /* SYSTEM FIRE_H_ */