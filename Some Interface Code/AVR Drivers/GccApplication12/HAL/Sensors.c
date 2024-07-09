/*
 * Sensors.c
 *
 * Created: 12/9/2022 4:47:44 AM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "ADC.h"
#include "Sensors.h"
#define F_CPU     16000000
#include <util/delay.h>
u16 Temp_Read(void)
{
	u16 volt=ADC_Read_volt(LM35_CH);
	u16 Temp =volt;
	return Temp;
}


u16 PRESS_Read(void){	u16 adc,press;	adc=ADC_Read(MPX4115_CH);		press=(((u32)1000*(adc-55))/921)+150;	return press;}


MQ_2 MQ_2_Read()
{
	if(DIO_ReadPin(MQ_2_Pin))
	{
		return NO_somke;
	}
	else
	{
		return  Smoke;
	}
}