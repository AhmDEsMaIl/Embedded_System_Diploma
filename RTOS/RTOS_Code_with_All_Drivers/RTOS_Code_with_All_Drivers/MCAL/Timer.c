/*
 * Timer.c
 *
 * Created: 2/11/2023 12:33:39 PM
 *  Author: ahmed
 */ 
#include "Timer.h"

/*************************Pointer to functions to be assigned to ISR*********************************/

static void (*Timer1_OVF_Fptr) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr) (void)=NULLPTR;
static void (*Timer2_OVF_Fptr) (void)=NULLPTR;
static void (*Timer2_OC2_Fptr) (void)=NULLPTR;
static void (*Timer0_OVF_Fptr) (void)=NULLPTR;
static void (*Timer0_OC0_Fptr) (void)=NULLPTR;
/******************************************************************************************/
/*timer 0 functions*/
void TIMER0_Init(Timer0Mode_type mode,Timer0Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLR_BIT(TCCR0_PR,WGM00_PR);
		CLR_BIT(TCCR0_PR,WGM01_PR);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0_PR,WGM00_PR);
		CLR_BIT(TCCR0_PR,WGM01_PR);
		break;
		case TIMER0_CTC_MODE:
		CLR_BIT(TCCR0_PR,WGM00_PR);
		SET_BIT(TCCR0_PR,WGM01_PR);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0_PR,WGM00_PR);
		SET_BIT(TCCR0_PR,WGM01_PR);
		break;
	}
	TCCR0_PR&=0XF8;//0b11111000
	TCCR0_PR|=scaler;
}

void TIMER0_OC0Mode(OC0Mode_type mode)
{
	switch (mode)
	{
		case OC0_DISCONNECTED:
		CLR_BIT(TCCR0_PR,COM00_PR);
		CLR_BIT(TCCR0_PR,COM01_PR);
		break;
		case OC0_TOGGLE:
		SET_BIT(TCCR0_PR,COM00_PR);
		CLR_BIT(TCCR0_PR,COM01_PR);
		break;
		case OC0_NON_INVERTING:
		CLR_BIT(TCCR0_PR,COM00_PR);
		SET_BIT(TCCR0_PR,COM01_PR);
		break;
		case OC0_INVERTING:
		SET_BIT(TCCR0_PR,COM00_PR);
		SET_BIT(TCCR0_PR,COM01_PR);
		break;
	}
}

void TIMER0_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,TOIE0_PR);
}
void TIMER0_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,TOIE0_PR);
}
void TIMER0_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,OCIE0_PR);
}
void TIMER0_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,OCIE0_PR);
}
/*********************************Timer 2 Call Back functions*****************************************/

void Timer0_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OVF_Fptr=LocalFptr;
}
void Timer0_OC0_SetCallBack(void(*LocalFptr)(void))
{
	Timer0_OC0_Fptr=LocalFptr;
}
/*********************************Timer 0 ISR functions*********************************************/
ISR(TIMER0_OVF_vect)
{
	if(Timer0_OVF_Fptr!=NULLPTR)
	{
		Timer0_OVF_Fptr();
	}
}
ISR(TIMER0_OC0_vect)
{
	if(Timer0_OC0_Fptr!=NULLPTR)
	{
		Timer0_OC0_Fptr();
	}
}

/*************************************************************************/
/*timer 1 functions*/
void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A_PR,WGM10_PR);
		CLR_BIT(TCCR1A_PR,WGM11_PR);
		CLR_BIT(TCCR1B_PR,WGM12_PR);
		CLR_BIT(TCCR1B_PR, WGM13_PR);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A_PR,WGM10_PR);
		CLR_BIT(TCCR1A_PR,WGM11_PR);
		SET_BIT(TCCR1B_PR,WGM12_PR);
		SET_BIT(TCCR1B_PR, WGM13_PR);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A_PR,WGM10_PR);
		CLR_BIT(TCCR1A_PR,WGM11_PR);
		SET_BIT(TCCR1B_PR,WGM12_PR);
		CLR_BIT(TCCR1B_PR, WGM13_PR);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A_PR,WGM10_PR);
		SET_BIT(TCCR1A_PR,WGM11_PR);
		SET_BIT(TCCR1B_PR,WGM12_PR);
		SET_BIT(TCCR1B_PR, WGM13_PR);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A_PR,WGM10_PR);
		SET_BIT(TCCR1A_PR,WGM11_PR);
		SET_BIT(TCCR1B_PR,WGM12_PR);
		SET_BIT(TCCR1B_PR, WGM13_PR);
		break;
	}

	TCCR1B_PR&=0XF8;
	TCCR1B_PR|=scaler;

}
void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A_PR,COM1A0_PR);
		CLR_BIT(TCCR1A_PR,COM1A1_PR);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A_PR,COM1A0_PR);
		CLR_BIT(TCCR1A_PR,COM1A1_PR);
		break;
		case OCRA_NON_INVERTING:
		CLR_BIT(TCCR1A_PR,COM1A0_PR);
		SET_BIT(TCCR1A_PR,COM1A1_PR);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A_PR,COM1A0_PR);
		SET_BIT(TCCR1A_PR,COM1A1_PR);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A_PR,COM1B0_PR);
		CLR_BIT(TCCR1A_PR,COM1B1_PR);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A_PR,COM1B0_PR);
		CLR_BIT(TCCR1A_PR,COM1B1_PR);
		break;
		case OCRB_NON_INVERTING:
		CLR_BIT(TCCR1A_PR,COM1B0_PR);
		SET_BIT(TCCR1A_PR,COM1B1_PR);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A_PR,COM1B0_PR);
		SET_BIT(TCCR1A_PR,COM1B1_PR);
		break;
	}
}
void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B_PR,ICES1_PR);
	
	else if(edge==FALLING)
	CLR_BIT(TCCR1B_PR,ICES1_PR);
}


/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,TICIE1_PR);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,TICIE1_PR);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,TOIE1_PR);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,TOIE1_PR);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,OCIE1A_PR);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,OCIE1A_PR);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,OCIE1B_PR);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,OCIE1B_PR);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}

/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULLPTR)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_OCA_vect)
{
	if(Timer1_OCA_Fptr!=NULLPTR)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_OCB_vect)
{
	if(Timer1_OCB_Fptr!=NULLPTR)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_ICU_vect)
{
	if(Timer1_ICU_Fptr!=NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}
/******************************************************************************************/
/*timer 2 functions*/
void TIMER2_Init(Timer2Mode_type mode,Timer2Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER2_NORMAL_MODE:
		CLR_BIT(TCCR2_PR,WGM20_PR);
		CLR_BIT(TCCR2_PR,WGM21_PR);
		break;
		case TIMER2_PHASECORRECT_MODE:
		SET_BIT(TCCR2_PR,WGM20_PR);
		CLR_BIT(TCCR2_PR,WGM21_PR);
		break;
		case TIMER2_CTC_MODE:
		CLR_BIT(TCCR2_PR,WGM20_PR);
		SET_BIT(TCCR2_PR,WGM21_PR);
		break;
		case TIMER2_FASTPWM_MODE:
		SET_BIT(TCCR2_PR,WGM20_PR);
		SET_BIT(TCCR2_PR,WGM21_PR);
		break;
	}
	TCCR2_PR&=0XF8;//0b11111000
	TCCR2_PR|=scaler;
}

void TIMER2_OC2Mode(OC2Mode_type mode)
{
	switch (mode)
	{
		case OC2_DISCONNECTED:
		CLR_BIT(TCCR2_PR,COM20_PR);
		CLR_BIT(TCCR2_PR,COM21_PR);
		break;
		case OC2_TOGGLE:
		SET_BIT(TCCR2_PR,COM20_PR);
		CLR_BIT(TCCR2_PR,COM21_PR);
		break;
		case OC2_NON_INVERTING:
		CLR_BIT(TCCR2_PR,COM20_PR);
		SET_BIT(TCCR2_PR,COM21_PR);
		break;
		case OC2_INVERTING:
		SET_BIT(TCCR2_PR,COM20_PR);
		SET_BIT(TCCR2_PR,COM21_PR);
		break;
	}
}

void TIMER2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,TOIE2_PR);
}
void TIMER2_OV_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,TOIE2_PR);
}
void TIMER2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK_PR,OCIE2_PR);
}
void TIMER2_OC_InterruptDisable(void)
{
	CLR_BIT(TIMSK_PR,OCIE2_PR);
}
/*********************************Timer 2 Call Back functions*****************************************/

void Timer2_OVF_SetCallBack(void(*LocalFptr)(void))
{
Timer2_OVF_Fptr=LocalFptr;
}
void Timer2_OC2_SetCallBack(void(*LocalFptr)(void))
{
	Timer2_OC2_Fptr=LocalFptr;
}
/*********************************Timer 2 ISR functions*********************************************/
ISR(TIMER2_OVF_vect)
{
	if(Timer2_OVF_Fptr!=NULLPTR)
	{
		Timer2_OVF_Fptr();
	}
}
ISR(TIMER2_OC2_vect)
{
	if(Timer2_OC2_Fptr!=NULLPTR)
	{
		Timer2_OC2_Fptr();
	}
}