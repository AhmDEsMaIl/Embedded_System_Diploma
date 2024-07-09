/*
 * ADC.c
 *
 * Created: 12/3/2022 7:27:53 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utiles.h"
#include "ADC.h"
#include "LCD.h"
#define F_CPU     16000000
#include<util/delay.h>

u8 static ADCFlag=1;

void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)
{
	/* clock*/ 
	scaler=scaler&0x07; //00000111
	ADCSRA=ADCSRA&0xf8; //11111000
	ADCSRA=ADCSRA|scaler;
	/* volt ref */
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;	
	}
	
	CLR_BIT(ADMUX,ADLAR);
	/* ADC ENABLE*/
	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc,t1,t2,y,x;
	 //select channel
		ADMUX=ADMUX&0xe0;
		ch=ch&0x1f;
		ADMUX=ADMUX|ch;	
	 //start conversion 
	SET_BIT(ADCSRA,ADSC);
	//w8 until finish
	while(READ_BIT(ADCSRA,ADSC));	
	 //get read 
	adc=ADC;
	return adc;

}

u16 ADC_Read_volt(ADC_Channel_type ch)
{
	u16 volt,adc ;
	
	adc=(ADC_Read(ch));
	volt=(adc*VREF)/1024;

	
	return volt ;
	

}
void ADC_StartConversion(ADC_Channel_type ch)
{
	if(ADCFlag==1)
	{
	//select channel
	ADMUX=ADMUX&0xe0;
	ch=ch&0x1f;
	ADMUX=ADMUX|ch;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	ADCFlag=0;
	}
}
u16 ADC_GetRead()
{
	while(READ_BIT(ADCSRA,ADSC));
	//get read
	return ADC ;

}
u8 ADC_GetReadPerodic(u16 *pdata)
{
	if(READ_BIT(ADCSRA,ADSC))
	{
		*pdata=ADC;
		ADCFlag=1;
		return 1;
	}
	else
	{
		return 0;
	}
}
u16 ADC_GetReadNoblock()
{
	//get read
	return ADC ;
}