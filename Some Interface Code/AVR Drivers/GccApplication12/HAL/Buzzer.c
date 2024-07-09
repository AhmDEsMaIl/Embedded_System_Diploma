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
void Fan_On (void)
{
	DIO_WritePin(Fan_Pin,HIGH);

}
void Fan_OFF (void)
{
	DIO_WritePin(Fan_Pin,LOW);

}