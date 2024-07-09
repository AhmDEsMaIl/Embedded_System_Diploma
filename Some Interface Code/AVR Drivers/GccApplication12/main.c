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
#include "Fire System.h"
#define F_CPU     16000000
#include <util/delay.h>
#define Global_Enable   sei
#include "Keypad.h"
// static volatile u16 dis=0;
// u16 T,P;
// u16 pass=1958;  

// volatile u16 x=0 ,num;
// u8 interput_timer=0,i;

// static volatile u16 NVM_interput_flag1,NVM_interput_flag2,n;
// static const u16 pass=1953;

u16 T=0;
MQ_2 S=0;
u16 ss=0;
void f3 (void)
{
	static u8 c=0;
	LCD_SetCursor(0,0);
	LCD_WriteNumber(c);
	c++;
}
int main(void)
{
	
	/*Replace with your application code */
    	INIT();
		EXI_Enable(EX_INT0);
		EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
		EXI_SetCallBack(EX_INT0,f3);
		while(1)
 		{
 		
        }
	
		
}

	


