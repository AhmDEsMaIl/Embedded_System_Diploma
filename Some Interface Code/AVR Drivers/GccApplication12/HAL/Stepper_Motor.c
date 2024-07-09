/*
 * Stepper_Motor.c
 *
 * Created: 2/18/2023 5:01:41 PM
 *  Author: ahmed
 */ 
#include "DIO_interface.h"
#include "StdTypes.h"
#include "Stepper_Motor.h"
#include "Timer.h"
#include "LCD.h"
#define F_CPU     16000000
#include <util/delay.h>
volatile static u8 f=0;
void Interpurt_Stepper()
{
	static u16 c=0;
	c++;
	if(c==DELAY)
	{
		f++;
		if(f==4)
		{
			f=0;
		}
		c=0;
	Stepper_Unipoler_CW_Interput();
	}
	
}

// ISR(TIMER1_OVF_vect)
// {
// 	  
// 	    /*LCD_SetCursor(2,0);
// 		LCD_WriteNumber(f);*/
// }
u8 Stepper_Unipoler_CW_Interput(void)
{
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_DISCONNECTED);
	Timer1_OCRB1Mode(OCRB_DISCONNECTED);
	ICR1=999;
	
	Timer1_OVF_SetCallBack(Interpurt_Stepper);
	
	Timer1_OVF_InterruptEnable();
	
	if(f==0)
	{
    DIO_WritePin(COLI1A,LOW);
    DIO_WritePin(COLI1B,HIGH);
    DIO_WritePin(COLI2A,LOW);
    DIO_WritePin(COLI2B,LOW);
	return 1;
	}
	if(f==1)
	{
    DIO_WritePin(COLI1A,LOW);
    DIO_WritePin(COLI1B,LOW);
    DIO_WritePin(COLI2A,HIGH);
    DIO_WritePin(COLI2B,LOW);

	return 1;
	}
    if(f==2)
    {
     DIO_WritePin(COLI1A,LOW);
     DIO_WritePin(COLI1B,LOW);
     DIO_WritePin(COLI2A,LOW);
     DIO_WritePin(COLI2B,HIGH);  
	return 1;
	}
    if(f==3)
    {
    DIO_WritePin(COLI1A,HIGH);
    DIO_WritePin(COLI1B,LOW);
    DIO_WritePin(COLI2A,LOW);
    DIO_WritePin(COLI2B,LOW);
	return 1;
	}

}
void Stepper_Unipoler_CW_OFF(void)
{
    Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_STOP);
}
void Stepper_Bipoler_CCW(void)
{
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
}
void Stepper_Unipoler_CW(void)
{

	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
}
u8 Stepper_Unipoler_CW_By_Rot(u8 Rot)
{
	u8 i=0;
	u16 rot=(360/Step_Size),Numb_Loop=0;
	if(rot%4==0)
	{
		Numb_Loop=(rot/4)*Rot;
		for(i=0;i<Numb_Loop;i++)
		{
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,HIGH);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,HIGH);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,HIGH);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,HIGH);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
		}
		return 1;
	}
	if(rot%4!=0)
	{
		Numb_Loop=(rot/4)*Rot;
		for(i=0;i<Numb_Loop;i++)
		{
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,HIGH);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,HIGH);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,LOW);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,HIGH);
			_delay_ms(DELAY);
			DIO_WritePin(COLI1A,HIGH);
			DIO_WritePin(COLI1B,LOW);
			DIO_WritePin(COLI2A,LOW);
			DIO_WritePin(COLI2B,LOW);
			_delay_ms(DELAY);
		}
		return 0;
	}
}
u8 Stepper_Unipoler_CW_Hs_By_angle(u16 Angle)
{
	static u16 c=0;
	u16 half_step=Step_Size/2;
	if(Angle%half_step==0)
	{
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	
	/*DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,HIGH);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	c+=half_step/2;
	if(c==Angle)
	{
		c=0;
		return 1;
	}
	else
	{
		Stepper_Unipoler_CW_Hs_By_angle(Angle);
	}
	}
	else if(Angle%half_step!=0)
	{
		DIO_WritePin(COLI1A,HIGH);
		DIO_WritePin(COLI1B,LOW);
		DIO_WritePin(COLI2A,LOW);
		DIO_WritePin(COLI2B,LOW);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,HIGH);
		DIO_WritePin(COLI1B,HIGH);
		DIO_WritePin(COLI2A,LOW);
		DIO_WritePin(COLI2B,LOW);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,LOW);
		DIO_WritePin(COLI1B,HIGH);
		DIO_WritePin(COLI2A,LOW);
		DIO_WritePin(COLI2B,LOW);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,LOW);
		DIO_WritePin(COLI1B,HIGH);
		DIO_WritePin(COLI2A,HIGH);
		DIO_WritePin(COLI2B,LOW);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,LOW);
		DIO_WritePin(COLI1B,LOW);
		DIO_WritePin(COLI2A,HIGH);
		DIO_WritePin(COLI2B,LOW);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,LOW);
		DIO_WritePin(COLI1B,LOW);
		DIO_WritePin(COLI2A,HIGH);
		DIO_WritePin(COLI2B,HIGH);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,LOW);
		DIO_WritePin(COLI1B,LOW);
		DIO_WritePin(COLI2A,LOW);
		DIO_WritePin(COLI2B,HIGH);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		DIO_WritePin(COLI1A,HIGH);
		DIO_WritePin(COLI1B,LOW);
		DIO_WritePin(COLI2A,LOW);
		DIO_WritePin(COLI2B,HIGH);
		c+=half_step/2;
		if(c>Angle)
		{
			c=0;
			return 0;
		}
		else
		{
			Stepper_Unipoler_CW_Hs_By_angle(Angle);
		}*/
	}
}
void Stepper_Unipoler_CCW(void)
{
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
}
void Stepper_Unipoler_CW_HS(void)
{

	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
}
void Stepper_Unipoler_CCW_HS(void)
{
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
    DIO_WritePin(COLI1A,LOW);
    DIO_WritePin(COLI1B,LOW);
    DIO_WritePin(COLI2A,LOW);
    DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,HIGH);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,HIGH);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
	_delay_ms(DELAY);
}