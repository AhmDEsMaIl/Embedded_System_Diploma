/*
 * Buzzer.c
 *
 * Created: 12/16/2022 6:52:27 PM
 *  Author: ahmed
 */ 

#include "DIO_interface.h"
#include "Buzzer.h"




void Buzzer_On (void)
{
	DIO_WritePin(Buzzer_Pin,HIGH);

}
void Buzzer_OFF (void)
{
	DIO_WritePin(Buzzer_Pin,LOW);

}

void Relay_On (u32 num)
{
	if(num==1)
	{
		DIO_WritePin(Relay_1_Pin,HIGH);
	}
	else
	{
		DIO_WritePin(Relay_2_Pin,HIGH);
	}
}
void Relay_Off (u32 num)
{
	if(num==1)
	{
		DIO_WritePin(Relay_1_Pin,LOW);
	}
	else
	{
		DIO_WritePin(Relay_2_Pin,LOW);
	}
}