/*
 * RGB.c
 *
 * Created: 2/11/2023 6:37:31 PM
 *  Author: ahmed
 */ 
#include "Utiles.h"
#include "RGB.h"
#include "Timer.h"
#include "MemMap.h"
#include "DIO_interface.h"
#include "LCD.h"
#define F_CPU     8000000
#include <util/delay.h>
/****************************************************CONFG****************************************************************/
RGB Color[Total_Colors]={{255,0,0},{0,255,0},{0,0,255},{255,160,16},{255,224,32},{255,208,160}
,{160,128,96},{128,128,128},{160,32,254},{100,118,135},{45,52,74},{118,96,138},{240,163,10},
{0,0,0},{85,255,255},{170,255,170}};
/****************************************************CONFG***************************************************************/	
void  Set_RGB(Colors C)
{
	if((Color[C].Red)==255)
	{
	    DIO_WritePin(PINB3,HIGH);
	}
	else if((Color[C].Red)!=255)
	{
		OCR0=Color[C].Red;
	}
    if(Color[C].Green==255)
	{
		DIO_WritePin(PIND5,HIGH);
	} 
	else if((Color[C].Green)!=255)
	{
		OCR1A=Color[C].Green;
	}
	if(Color[C].Bule==255)
	{
		DIO_WritePin(PIND4,HIGH);
	}
	else if((Color[C].Bule)!=255)
	{
		OCR1B=Color[C].Bule;
	}
	
}
 /*void switch_red_to_green()
 {
 	static u8 c=0,flag=0;
	TCNT2=6;
	
	   if(c==20)
	   {
		 if(flag==0)
		 {
		OCR0--;
		OCR1A++;;
		 }
		 if(flag==1)
		 {
			OCR0++;
			OCR1A--;; 
		 }
		if(OCR0==0&& flag==0)
		{
			OCR0=0;
 			DIO_WritePin(PIND5,HIGH);
 			OCR1A=255;
			DIO_WritePin(PIND5,LOW);
			flag=1;
		}
		else if(OCR0==255&& flag==1)
		{
			DIO_WritePin(PINB3,HIGH);
			OCR0=255;
			OCR1A=0;
			DIO_WritePin(PINB3,LOW);
			flag=0;
		}
		c=0;
	   }
	
	c++;
  }*/
// void red_to_green()
// {
// 	static u8 flag=0;
// 	if(flag==0)
// 	{
// 		DIO_WritePin(PINB3,HIGH);
// 		OCR0=255;
// 		OCR1A=0;
// 		OCR1B=0;
// 		DIO_WritePin(PINB3,LOW);
// 		flag=1;
// 	}
// 	Timer2_OVF_SetCallBack(switch_red_to_green);
// }
volatile static u8 I1,I2,f1=0,f2=0,f3=0;
volatile static u8 flag=0;
void Show_off_interput()
{
	static u8 c=0,f=0;
	//static u8 c1,c2;
	TCNT2=6;
	//c1++;
	/*LCD_SetCursor(0,3);
	LCD_WriteNumber(c1);*/
	if(c==200)
	{
		
	if(f==0)
	{
	if((Color[I1].Red)==255)
	{
		TIMER0_OC0Mode(OC0_NON_INVERTING);
		OCR0=254;
	}
	if((Color[I1].Green)==255)
	{
        Timer1_OCRA1Mode(OCRA_NON_INVERTING);
		OCR1A=254;
	}
	if((Color[I1].Bule)==255)
	{
		Timer1_OCRB1Mode(OCRB_NON_INVERTING);
		OCR1B=254;
	}
	f=1;
	}
	if(f1==0)
	{
	if(OCR0>Color[I2].Red)
	{
		OCR0--;
		/*LCD_SetCursor(0,0);
		LCD_WriteNumber(OCR0);*/
		
	}
	else if(OCR0<Color[I2].Red)
	{
		OCR0++;

	}
	else if(OCR0==Color[I2].Red)
	{
		OCR0=Color[I2].Red;
		f1=1;
		if((Color[I2].Red)==255)
		{
			TIMER0_OC0Mode(OC0_INVERTING);
			OCR0=0;	
		}
	}
	}
	if(f2==0)
	{
	if(OCR1A>Color[I2].Green)
	{
		OCR1A--;
		/*LCD_SetCursor(1,0);
		LCD_WriteNumber(OCR1A);*/
	}
	else if(OCR1A<Color[I2].Green)
	{
		OCR1A++;
		/*LCD_SetCursor(1,6);
		LCD_WriteNumber(OCR1A);*/
	}
	else if(OCR1A==Color[I2].Green)
	{
		OCR1A=Color[I2].Green;
		/*LCD_SetCursor(1,10);
		LCD_WriteNumber(Color[I2].Green);*/
		f2=1;
		if(Color[I2].Green==255)
		{
			Timer1_OCRA1Mode(OCRA_INVERTING);
			OCR1A=0;
			
		}
	}
	}
	if(f3==0)
    {
	if(OCR1B>Color[I2].Bule)
	{
		OCR1B--;
	}
	else if(OCR1B<Color[I2].Bule)
	{
		OCR1B++;
	}
	else if(OCR1B==Color[I2].Bule)
	{
		OCR1B=Color[I2].Bule;
		f3=1;
		if(Color[I2].Bule==255)
		{
			Timer1_OCRB1Mode(OCRB_INVERTING);
			OCR1B=0;	
		}
	}
	}
	c=0;
     }
	c++;
	if(f1==1 && f2==1 && f3==1)
	{
		TIMER2_OV_InterruptDisable();
		f=0;
		flag=0;
		f1=0;
        f2=0;
		f3=0;
		/*LCD_SetCursor(1,14);
		LCD_WriteNumber(flag);*/
	}
	
}

void Show_off(Colors C1, Colors C2)
{
	//static u8 c=0;
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	TIMER2_OV_InterruptEnable();
	ICR1=255;
	if(flag==0)
	{
	if((Color[C1].Red)==255)
	{
		TIMER0_OC0Mode(OC0_INVERTING);
		OCR0=0;
	}
	else if((Color[C1].Red)!=255)
	{
		OCR0=Color[C1].Red;
	}
	if(Color[C1].Green==255)
	{
	   Timer1_OCRA1Mode(OCRA_INVERTING);
		OCR1A=0;
	}
	else if((Color[C1].Green)!=255)
	{
		OCR1A=Color[C1].Green;
	}
	if(Color[C1].Bule==255)
	{
		Timer1_OCRB1Mode(OCRB_INVERTING);
        OCR1B=0;
	}
	else if((Color[C1].Bule)!=255)
	{
		OCR1B=Color[C1].Bule;
	}
	I1=C1;
	I2=C2;
	flag=1;
	//c++;
	}
	/*LCD_SetCursor(0,0);
	LCD_WriteNumber(c);*/
	Timer2_OVF_SetCallBack(Show_off_interput);
}
void Swang(void)
{
	
   Show_off(Black,Black_grey);
   /*LCD_SetCursor(1,0);
   LCD_WriteNumber(flag);*/
   while(flag==1);
  /*_delay_ms(100);
   LCD_SetCursor(1,6);
   LCD_WriteNumber(flag);*/
   Show_off(Black_grey,Grey);
   while(flag==1);
   Show_off(Grey,Brown);
   while(flag==1);
   Show_off(Brown,steel);
   while(flag==1);
   Show_off(steel,Bule);
   while(flag==1);
   /*LCD_SetCursor(1,14);
   LCD_WriteNumber(flag);*/
   Show_off(Bule,SkyBule);
   while(flag==1);
   Show_off(SkyBule,Light_Green);
   while(flag==1);
   Show_off(Green,Red);
   while(flag==1);
   Show_off(Red,Purple);
   while(flag==1);
   Show_off(Purple,Black);
}

