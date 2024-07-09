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
//SemaphoreHandle_t semSynch;

void Task1_LcdUpdate(void*pvParamter)
{
	u8 Msg_Lcd[] 		= "T1";
	LCD_SetCursor_2(0,0);
	LCD_WriteString(Msg_Lcd);
	u8 btn_Prsd[] 	 	= "Prs#";
	u8 counter = 0;
	while(1)
	{
		//  Take
		xSemaphoreTake(semSynch, portMAX_DELAY);
		//xSemaphoreTake(semSynch, (portTickType)0);
		// Update LCD with pressing message
		LCD_SetCursor_2(1,0);
		LCD_WriteString(btn_Prsd);
		LCD_SetCursor_2(1,10);
		LCD_WriteNumber(counter);
		counter++;
		vTaskDelay(200);

	}

}


void Task2_ButtonCheck(void*pvParamter)
{
	//  Take
	//xSemaphoreTake(semSynch, (portTickType)0);

	while(1)
	{
		if ((DIO_ReadPin(PINA0_PR))== LOW)
		{
			DIO_TogglePin(PINB0_PR);
			// Give
			xSemaphoreGive(semSynch);
		}
		else
		{
			DIO_TogglePin(PINB2_PR);
		}
		vTaskDelay(200);
	}

}




// xSemaphoreHandle semSynch = NULL;


//  Take
//xSemaphoreTake(semSynch, portMAX_DELAY);
// Give
//xSemaphoreGive(semSynch);
