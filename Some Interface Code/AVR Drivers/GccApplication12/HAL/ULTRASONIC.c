/*
 * ULTRASONIC.c
 *
 * Created: 2/14/2023 10:24:18 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "DIO_interface.h"
#include "Timer.h"
#include "ULTRASONIC.h"
#include "LCD.h"
#define  F_CPU 16000000
#include <util/delay.h>

static volatile u16 t1,t2;
static volatile u8 flag=0;
static volatile u16 arr [Numb_US]={0};
 
static void f1(void);

void ULTRASONIC_Init(void)
{
	Timer1_ICU_SetCallBack(f1);
	Timer1_ICU_InterruptEnable();
}

u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16*pdistance)
{
	u16 t,d;
	TCNT1=0;
	flag=0;
	u16 c=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(us,HIGH);
	_delay_us(10);
	DIO_WritePin(us,LOW);
	while((flag<2)&&(c<23000))
	{
		c++;
		_delay_us(1);
	}
	if (flag==2)
	{
		t=t2-t1;
		d=t/58;
		*pdistance=d;
		_delay_ms(10);
		return 1;
	}
	
	return 0;
}

static void f1(void)
{
	
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
	}
}
void Four_UltraSonic_Init(void)
{
	 ULTRASONIC_Init();

}
void Four_UltraSonic_Runnable(void)
{
	u16 dis=0;
	u8 x;
	if((ULTRASONIC_GetDistance(US1,&dis)))
	{
		arr[0]=dis;
		dis=0;
	}
	else
	{
		arr[0]=0;
	}
	if((ULTRASONIC_GetDistance(US2,&dis)))
	{
		arr[1]=dis;
		dis=0;
	}
	else
	{
		arr[1]=0;
	}
	if((ULTRASONIC_GetDistance(US3,&dis)))
	{
		arr[2]=dis;
		dis=0;
	}
	else
	{
		arr[2]=0;
	}
	if((ULTRASONIC_GetDistance(US4,&dis)))
	{
		arr[3]=dis;
		dis=0;
	}
	else
	{
		arr[3]=0;
	}

}
u16 Four_UltraSonic_get_distance(ULTRASONIC_type us)
{
	if(us==US1)
	{
	return arr[0];
	}
	if(us==US2)
	{
		return arr[1];
	}
	if(us==US3)
	{
		return arr[2];
	}
	if(us==US4)
	{
		return arr[3];
	}
}
/*typedef enum {
	even,
	odd
	}parity_type;

u16 uartframe(u8 data ,parity_type parity)
{
	u16 frame=0;
	u8 data2=data;
	u8 c=0;
	u8 p_bit;
	while(data)
	{
		c+=data&1;
		data>>=1;
	}
	if(c%2==0)&&parity==even)
	{
		p_bit=0;
	}
	
	frame=(u16)data2<<1;
	frame=frame|((u16)p_bit<<9);
	frame=frame|(1<<10);
	return frame;
	
}



*/
