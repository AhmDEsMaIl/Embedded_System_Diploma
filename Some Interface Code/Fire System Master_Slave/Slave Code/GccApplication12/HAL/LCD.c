/*
 * LCD.c
 *
 * Created: 11/13/2022 10:09:56 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "Utiles.h"

#define  F_CPU 8000000
#include <util/delay.h>

u8 LCD_Count =0;

#if  LCD_MODE==_4_Bit
static void WriteIns(u8 ins)
{
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void WriteData(u8 ins)
{
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X02);
	WriteIns(0X28);
	WriteIns(0X0c);//0x0e,0x0f cursor
	WriteIns(0X01);//clear screen
	_delay_ms(1);
	WriteIns(0X06);
	
}
#elif LCD_MODE==_8_Bit
static void WriteIns(u8 ins)
{
	
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void WriteData(u8 data)
{
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X38);// 8_Bit_Mode
	WriteIns(0X0c);//0x0e,0x0f cursor
	WriteIns(0X01);//clear screen
	_delay_ms(1);
	WriteIns(0X06);
	
}
#endif


void LCD_Clear(void)
{
	WriteIns(0X01);//clear screen
	_delay_ms(1);
}
void LCD_Clear_With_Began (u8 line ,u8 cell,u8 spaces)
{
	u8 i;
	//LCD_SetCursor(line,cell);
	for(i=0;i<spaces;i++)
	{
		LCD_WriteChar(' ');
	}
	LCD_SetCursor(line,cell);
}

void LCD_WriteNumber(s32 num)
{
	u8 str[10];
	s8 i=0;
    if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		LCD_WriteChar('-');
		num=num*(-1);
	}
	while(num)
	{
		str[i]=(num%10)+'0';
		num=num/10;
		i++;
	}
	i--;
	while(i!=-1)
	{
		LCD_WriteChar(str[i]);
		i--;
	}

}
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
	
	
}
u8 string_length(c8 str[])
{
	u8 i=0;
	for(i=0;str[i];i++)
	{

	}
	
	return i;
}
void LCD_WriteString(c8*str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		
		
		LCD_WriteChar(str[i]);
		
	}
}
void set_CGRam()
{
	u8 arr[][8]={{0xff,0x0f,0x65,0xc4,0xb7,0xa9,0xe7,0xff}};
      WriteIns(0x40);
	  WriteData(arr);

}
void LCD_SetCursor(u8 line ,u8 cell)
{
	
	switch(line)
	{
		case 0:
		switch(cell)
		{
			case 0:
			WriteIns(0x80);
			break;
			case 1:
			WriteIns(0x81);
			break;
			case 2:
			WriteIns(0x82);
			break;
			case 3:
			WriteIns(0x83);
			break;
			case 4:
			WriteIns(0x84);
			break;
			case 5:
			WriteIns(0x85);
			break;
			case 6:
			WriteIns(0x86);
			break;
			case 7:
			WriteIns(0x87);
			break;
			case 8:
			WriteIns(0x88);
			break;
			case 9:
			WriteIns(0x89);
			break;
			case 10:
			WriteIns(0x8a);
			break;
			case 11:
			WriteIns(0x8b);
			break;
			case 12:
			WriteIns(0x8c);
			break;
			case 13:
			WriteIns(0x8d);
			break;
			case 14:
			WriteIns(0x8e);
			break;
			case 15:
			WriteIns(0x8f);
			break;
		}
		break;
		case 1:
		switch(cell)
		{
			case 0:
			WriteIns(0xc0);
			break;
			case 1:
			WriteIns(0xc1);
			break;
			case 2:
			WriteIns(0xc2);
			break;
			case 3:
			WriteIns(0xc3);
			break;
			case 4:
			WriteIns(0xc4);
			break;
			case 5:
			WriteIns(0xc5);
			break;
			case 6:
			WriteIns(0xc6);
			break;
			case 7:
			WriteIns(0xc7);
			break;
			case 8:
			WriteIns(0xc8);
			break;
			case 9:
			WriteIns(0xc9);
			break;
			case 10:
			WriteIns(0xca);
			break;
			case 11:
			WriteIns(0xcb);
			break;
			case 12:
			WriteIns(0xcc);
			break;
			case 13:
			WriteIns(0xcd);
			break;
			case 14:
			WriteIns(0xce);
			break;
			case 15:
			WriteIns(0xcf);
			break;
		}
		break;
	}
}
void LCD_WriteBinary(u8 num)
{
	u8 arr[7],i,j=7;
	for(i=0;i<8;i++)
	{
		arr[i]=check_BIT(num,i);
	}
	i--;
	for(j=0;j<8;j++)
	{
		LCD_WriteChar(arr[i]+'0');
		i--;
	}
	
}
void LCD_WriteHex(u8 num)
{
	s8 remd=0,arr[10],i=0,j;
	while(num!=0)
	{
		remd=num%16;
		if(remd<10)
		{
			arr[i++]=48+remd;
		}
		else
		{
			arr[i++]=55+remd;
		}
		num=num/16;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(arr[j]);
	}
}

void LCD_WriteNumber_4D(u16 num)
{
	// incompelete we must revese squencce of display to display right num
	LCD_WriteChar(num%10+'0');
	num=num/10;
	LCD_WriteChar(num%10+'0');
	num=num/10;
	LCD_WriteChar(num%10+'0');
	num=num/10;
	LCD_WriteChar(num%10+'0');
	num=num/10;
	
}