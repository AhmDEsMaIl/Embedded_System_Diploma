/*
 * Servo_Motor.c
 *
 * Created: 2/20/2023 2:48:41 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "Timer.h"
void Servo_On()
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
}
void Servo_Set_Angle(u32 angle)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	ICR1=19999;
	OCR1A=((angle*1000)/180)+999;
}
void Servo_Off()
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_STOP);
	Timer1_OCRA1Mode(OCRA_DISCONNECTED);
}