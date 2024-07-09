/*
 * Stepper_Motor.c
 *
 * Created: 2/17/2023 7:43:28 PM
 *  Author: ahmed
 */ 
#include "DIO_interface.h"
#include "StdTypes.h"
#include "Stepper_Motor.h"
#define F_CPU     8000000
#include <util/delay.h>
void Stepper_Bipoler_CW(void)
{
	DIO_WritePin(COLI1A,HIGH);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,LOW);
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
	DIO_WritePin(COLI1A,LOW);
	DIO_WritePin(COLI1B,LOW);
	DIO_WritePin(COLI2A,LOW);
	DIO_WritePin(COLI2B,HIGH);
	_delay_ms(DELAY);
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