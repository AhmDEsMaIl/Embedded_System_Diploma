/*
 * ADC.c
 *
 * Created: 12/3/2022 7:27:53 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC.h"
#include "LCD.h"
#define F_CPU     8000000
#include<util/delay.h>

u8 static ADCFlag=1;

void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)
{
	/* clock*/ 
	scaler=scaler&0x07; //00000111
	ADCSRA_PR=ADCSRA_PR&0xf8; //11111000
	ADCSRA_PR=ADCSRA_PR|scaler;
	/* volt ref */
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX_PR,REFS0_PR);
		CLR_BIT(ADMUX_PR,REFS1_PR);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX_PR,REFS0_PR);
		CLR_BIT(ADMUX_PR,REFS1_PR);
		break;
		case VREF_256:
		SET_BIT(ADMUX_PR,REFS0_PR);
		SET_BIT(ADMUX_PR,REFS1_PR);
		break;	
	}
	
	CLR_BIT(ADMUX_PR,ADLAR_PR);
	/* ADC ENABLE*/
	SET_BIT(ADCSRA_PR,ADEN_PR);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc,t1,t2,y,x;
	 //select channel
		ADMUX_PR=ADMUX_PR&0xe0;
		ch=ch&0x1f;
		ADMUX_PR=ADMUX_PR|ch;	
	 //start conversion 
	SET_BIT(ADCSRA_PR,ADSC_PR);
	//w8 until finish
	while(READ_BIT(ADCSRA_PR,ADSC_PR));	
	 //get read 
	adc=ADC_PR;
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
	ADMUX_PR=ADMUX_PR&0xe0;
	ch=ch&0x1f;
	ADMUX_PR=ADMUX_PR|ch;
	//start conversion
	SET_BIT(ADCSRA_PR,ADSC_PR);
	ADCFlag=0;
	}
}
u16 ADC_GetRead()
{
	while(READ_BIT(ADCSRA_PR,ADSC_PR));
	//get read
	return ADC_PR ;

}
u8 ADC_GetReadPerodic(u16 *pdata)
{
	if(READ_BIT(ADCSRA_PR,ADSC_PR))
	{
		*pdata=ADC_PR;
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
	return ADC_PR ;
}