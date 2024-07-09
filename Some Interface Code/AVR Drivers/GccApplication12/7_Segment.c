/*
 * _7_Segment.c
 *
 * Created: 11/2/2022 2:44:29 PM
 *  Author: ahmed
 */ 
#include "MemMap.h"
#include "Utiles.h"
#include "StdTypes.h"

#include<util/delay.h>
#define CPU_F     16000000


//////////////////////////////////////config_7_Segment///////////////////////////////////////////
#define   Segment_Port       PORTA


void segment_dis(char n)
{
	u8 arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	PORTD=arr[n/10];
	PORTC=arr[n%10];
}
void segment_dis_BCD(char n)
{
	//char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	char d0=n%10;
	char d1=n/10;
	PORTC=d0|d1<<4;
	
}
void segment_dis_BCD_hex(char n)
{
	//char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

	PORTC=n;
	
}

void segment_dis_MLX(char n)
{
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	char d0=n%10;
	char d1=n/10;
	SET_BIT(PORTC,6);
	PORTA=arr[d0]<<1;
	
	CLR_BIT(PORTD,7);
	
	_delay_ms(1);
	SET_BIT(PORTC,7);
	PORTA=arr[d1]<<1;
	
	CLR_BIT(PORTC,6);
	_delay_ms(1);
	
}