/*
 * Tasks.c
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */



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
#include "semphr.h"
#include "MyTasks.h"

xSemaphoreHandle semSynch = NULL;

void Task1_High(void*pvParamter)
{
	u8 message[]= "High R";
	while(1)
	{
		xSemaphoreTake(semSynch, portMAX_DELAY);
		LCD_Clear();
		LCD_SetCursor_2(0,0);
		LCD_WriteString(message);
		_delay_ms(500);

	}
}

void Task2_Medium(void*pvParamter)
{
	static u16 x = 0;
	static u16 flag = 0;
	while(1)
	{

		if(flag >= 5)
		{
			LCD_Clear();
			LCD_SetCursor_2(0,0);
			LCD_WriteNumber(x++);
			if( (DIO_ReadPin(PINA2_PR)) == LOW)
			{
				xSemaphoreGive(semSynch);
				flag = 0;
			}
			_delay_ms(1000);
		//	vTaskDelay(1000);
		}
		else
		{
			DIO_TogglePin(PINB0_PR);
			DIO_TogglePin(PINB2_PR);
			flag++;

			vTaskDelay(1000);
		}

	}
}

void Task3_Low(void*pvParamter)
{

	u8 message[]= "Low R";
	static u8 counter = 0;
	LCD_Clear();
	LCD_SetCursor_2(0,0);
	LCD_WriteString(message);
	LCD_SetCursor_2(1,0);
	LCD_WriteNumber(counter);
	while(1)
	{
		LCD_Clear();
		LCD_SetCursor_2(0,0);
		LCD_WriteString(message);
		LCD_SetCursor_2(1,0);
		LCD_WriteNumber(counter);
		_delay_ms(100);
		if( (DIO_ReadPin(PINA0_PR)) == LOW)
		{
			counter++;
			if(counter >= 2)
			{
				counter = 0;
				xSemaphoreGive(semSynch);
			}
		}
		vTaskDelay(200);
	}


}




