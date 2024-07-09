/*
 * Tasks.c
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */

#include "MyTasks.h"

#include <util/delay.h>
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "LCD.h"
//#include "KeyPad.h"
//#include "ADC.h"
//#include "Sensors.h"
//#include "EXInterrupt.h"
//#include "Timers.h"
//#include "TimerServices.h"
//#include "servo.h"
//#include "ultrasonic.h"
//#include "UART_Services.h"
//#include "UART.h"
//#include "SPI.h"


#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

 void Task1_LcdUpdate(void*pvParamter)
{
	static u8 letter ='a';
	static u8 position = 0;
	while(1)
	{
		if(letter >= 'z')
		{
			letter = 'a';
		}
		if(position >= 15)
		{
			LCD_Clear();
			position = 0;
		}
		LCD_SetCursor_2(1,position++);
		LCD_WriteChar(letter++);
		/**********Wait*********/
		vTaskDelay(500);
		LCD_SetCursor_2(0,10);
		LCD_WriteString("aaaaaaaaaaaaaaaa");
		//LCD_Clear();
	}
}


void Task2_LcdUpdate(void*pvParamter)
{
	static u8 letter = 'z';
	static u8 let = 'a';
	while(1)
	{
		if(letter == 'Z')
		{
			letter = 'z';
		}
		else
		{
			letter = 'Z';
		}
		LCD_SetCursor_2(0,4);
		LCD_WriteChar(letter);

		/**********Wait*********/
		vTaskDelay(500);
		LCD_SetCursor_2(0,0);
		LCD_WriteChar(let++);
	}
}



void Task3_Blink_L2(void*pvParamter)
{
	while(1)
	{

		DIO_TogglePin(PINB0_PR);
		_delay_ms(2000);
		/**********Wait*********/
		vTaskDelay(100);
	}
}


void vApplicationIdleHook(void)
{	while(1)
	{

		DIO_TogglePin(PINB2_PR);
		_delay_ms(2000);
		/**********Wait*********/
		vTaskDelay(100);
	}
}
void vApplicationTickHook( void )
{
	while(1)
	{
	static u16 Tick_Counter=0;
	Tick_Counter++;
	LCD_SetCursor_2(0,5);
	LCD_WriteNumber(Tick_Counter);
	if(Tick_Counter==0xFFFF)
	{
		Tick_Counter=0;
	}
	}
}





//vTaskDelay(1000);
