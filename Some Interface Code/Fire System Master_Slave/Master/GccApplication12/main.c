/*
 * GccApplication12.c
 *
 * Created: 11/2/2022 2:43:34 PM
 * Author : ahmed
 */ 

#include "MemMap.h"
#include "Utiles.h"
#include "StdTypes.h"
#include "DIO_interface.h"
#include "Motor_interface.h"
#include "Motor_cfg.h"
#include "LCD.h"
#include "ADC.h"
#include "LED.h"
#include "Sensors.h"
#include "Temp_Filter.h"
#include "Buzzer.h"
#include "Interrupt.h"
#include "NVM.h"
#include "Timer.h"
#include "RGB.h"
#include "Timer_Services.h"
#include "ULTRASONIC.h"
#include "Stepper_Motor.h"
#include "Servo_Motor.h"
#include "URAT.h"
#include "URAT_Services.h"
#include "System Fire.h"
#include "SPI.h"
#define F_CPU     8000000
#include <util/delay.h>
#define Global_Enable   sei
#include "Keypad.h"
volatile u8 Temp,f1;
void f3(void)
{
	Temp=SPI_SendReceieve(0);
	f1=1;
}
int main(void)
{
	/*Replace with your application code */
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	Temp_FilterInit();
	/*EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	EXI_Enable(EX_INT1);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	TIMER0_Init(TIMER0_PHASECORRECT_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_INVERTING);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2_SCALER_8);
	TIMER2_OC2Mode(OC2_NON_INVERTING);
	Four_UltraSonic_Init();
	TIMER2_OV_InterruptEnable();*/
	URAT_INIT();
	SPI_Init(Master);
	Global_Enable();
	u8 x=0,data=0,i=0,str[20],Nstr[20];
	u8 num;
// 	 LCD_SetCursor(0,0);
// 	 LCD_WriteString("SPI_MASTER");
// 	URAT_SendStringAshync("Ahmed");
// 	URAT_SendStringAshync("ikp");
// 	URAT_SendStringAshync("jjj");
// 	_delay_ms(3);
//   	URAT_SendStringAshync("kkked");


  /* u8 c=0,REC,SEN='0';*/
    EXI_Enable(EX_INT2);
    EXI_TriggerEdge(EX_INT2,RISING_EDGE);
    u8 c=0;
	Temp=SPI_Receieve();
	LCD_SetCursor(0,0);
	LCD_WriteNumber(Temp);
	EXI_SetCallBack(EX_INT2,f3);
  	while(1)             
 	{    //LCD_Clear();
		 //LCD_SetCursor(0,0);
		 LCD_WriteString("               ");
		 LCD_SetCursor(0,0);
		 LCD_WriteString("TEMP:");
		LCD_WriteNumber(Temp); 
		LCD_WriteChar('C');	 
	 if(!DIO_ReadPin(PINC7))
		{
			
			Temp=SPI_SendReceieve(0);	
		}
	   if(f1==0)
	   {
		   LCD_SetCursor(1,0);
		   LCD_WriteString("NOT ABOVE 50 C");
		   f1=2;
	   }
	   else if(f1==1)
	   {
		   LCD_SetCursor(1,0);
		   LCD_WriteString("ABOVE 50 C");
		   f1=0;
	   }
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		  
//   /* REC=SPI_SendReceieve(SEN);*/
// 	 if(!READ_BIT(DIO_ReadPin(PINB7))) 
// 	 {
// 		 Temp=SPI_SendReceieve(0);
// 		 LCD_SetCursor(0,0);
// 		 LCD_WriteNumber(Temp);
// 	 }
// 	  
// 	LCD_SetCursor(1,0);
// 	LCD_WriteNumber(c);
// 	c++;
// 	if(c==10)
// 	{
// 		c=0;
// 	}
// 	//_delay_ms(3000);   	
	}
}




