/*
 * Motor.c
 *
 * Created: 11/4/2022 11:34:47 PM
 *  Author: ahmed
 */ 
#define  F_CPU 8000000
#include <util/delay.h>

#include "Utils.h"
#include "MemMap.h"
#include "Motor_cfg.h"
#include "Motor_interface.h"
#include "DIO_interface.h"
u8 f1=255,f2=0;
void Motor_With_2_Bottom(DIO_Pin_type pin1,DIO_Pin_type pin2)
{
	/*if(f1==0)
	{
		DIO_WritePin(PINB4,HIGH);
		/*Motor_on_relay1_cw();
		_delay_ms(1000);
		DIO_WritePin(PINB4,LOW);
	}
	if(f1==255)
	{
		DIO_WritePin(PINB4,LOW);
		/*Motor_off_relay1_cw();
		_delay_ms(1000);
		DIO_WritePin(PINB6,LOW);
	}*/
	
	if(DIO_ReadPin(pin1)==LOW)
	{
		f1=~f1;
		while(!(DIO_ReadPin(pin1)));
	}	
	if(DIO_ReadPin(pin2)==LOW && f1==0)
	{
		
		f2=~f2;
		while(!(DIO_ReadPin(pin2)));
	}
	
		if(f2==0 && f1==0)
		{
			Motor_on_relay1_cw();
			Motor_off_relay2_antiCw();
			for(int i=0;i<100;i++)
			{
				if(DIO_ReadPin(pin2)==LOW || DIO_ReadPin(pin2)==LOW )
				{
					break;
				}
				else
				{
					_delay_ms(10);
				}
			}
			
		}
		 if(f2==255 && f1==0)
		{
			Motor_on_relay2_antiCw();
			Motor_off_relay1_cw();
			for(int i=0;i<100;i++)
			{
				if(DIO_ReadPin(pin2)==LOW || DIO_ReadPin(pin2)==LOW )
				{
					break;
				}
				else
				{
					_delay_ms(10);
				}
			}
		}
		 if(f1==255)
		{
			Motor_off_relay1_cw();
			Motor_off_relay2_antiCw();
			for(int i=0;i<10;i++)
			{
				if(DIO_ReadPin(pin2)==LOW || DIO_ReadPin(pin2)==LOW )
				{
					break;
				}
				else
				{
					_delay_ms(10);
				}
			}
		}
	
	
}
void Motor_on_relay1_cw(void)
{
	DIO_WritePin(relay1pin,HIGH);
}

void Motor_off_relay1_cw(void)
{
	DIO_WritePin(relay1pin,LOW);
}
void Motor_on_relay2_antiCw(void)
{
	
	DIO_WritePin(relay2pin,HIGH);
}
void Motor_off_relay2_antiCw(void)
{
	
	DIO_WritePin(relay2pin,LOW);
}

/*void MOTOR_Stop(MOTOR_type motor)
{
	if (motor>NUMBER_MOTORS)
	{
		return OUT_OF_RANGE;
	}
	MOTOR_type i;
	DIO_PinVoltage_type j
	for(i=M1;i<5;i++)
	{
	   for(j=)	
	DIO_WritePin(M1_IN1,LOW);
	DIO_WritePin(M1_IN2,LOW);
	
}*/
void MOTOR_CW(MOTOR_type motor)
{
	DIO_WritePin(M1_IN1,HIGH);
	DIO_WritePin(M1_IN2,LOW);
}
void MOTOR_CCW(MOTOR_type motor)
{
	DIO_WritePin(M1_IN1,LOW);
	DIO_WritePin(M1_IN2,HIGH);
}