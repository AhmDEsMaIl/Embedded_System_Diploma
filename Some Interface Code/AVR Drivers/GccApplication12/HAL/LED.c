/*
 * LED.c
 *
 * Created: 12/9/2022 1:24:43 AM
 *  Author: ahmed
 */ 
#include "DIO_interface.h"
#include "LED.h"
void LED_ON(u8 LED_Numb)
{
	switch(LED_Numb)
	{
		case 1:
		DIO_WritePin(_1_LED_Pin,HIGH);
		break;
		case 2:
		DIO_WritePin(_2_LED_Pin,HIGH);
		break;
		case 3:
		DIO_WritePin(_3_LED_Pin,HIGH);
		break;
		case 4:
		DIO_WritePin(_4_LED_Pin,HIGH);
		break;
		case 5:
		DIO_WritePin(_5_LED_Pin,HIGH);
		break;
		case 6:
		DIO_WritePin(_6_LED_Pin,HIGH);
		break;
		case 7:
		DIO_WritePin(_7_LED_Pin,HIGH);
		break;
		case 8:
		DIO_WritePin(_8_LED_Pin,HIGH);
		break;
	}
}
void LED_OFF(u8 LED_Numb)
{
	switch(LED_Numb)
	{
		case 1:
		DIO_WritePin(_1_LED_Pin,LOW);
		break;
		case 2:
		DIO_WritePin(_2_LED_Pin,LOW);
		break;
		case 3:
		DIO_WritePin(_3_LED_Pin,LOW);
		break;
		case 4:
		DIO_WritePin(_4_LED_Pin,LOW);
		break;
		case 5:
		DIO_WritePin(_5_LED_Pin,LOW);
		break;
		case 6:
		DIO_WritePin(_6_LED_Pin,LOW);
		break;
		case 7:
		DIO_WritePin(_7_LED_Pin,LOW);
		break;
		case 8:
		DIO_WritePin(_8_LED_Pin,LOW);
		break;
	}
}