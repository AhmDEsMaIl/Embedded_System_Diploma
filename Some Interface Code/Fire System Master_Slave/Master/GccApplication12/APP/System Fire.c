/*
 * System_Fire.c
 *
 * Created: 3/1/2023 2:21:30 AM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "LED.h"
#include "Servo_Motor.h"
#include "Buzzer.h"
#include "System Fire.h"
#include "RGB.h"
/************************************************************CONFG*************************************************************************/
u8 arr[Number_OF_TASKS][ARRAY1_SIZE]={{"LEDON_5"},{"LEDOFF_5"},{"SERVOON_30"},{"SERVOOFF_0"},{"RELAYON_1"},{"RELAYOFF_1"}};
TASKS_t TASKS[Number_OF_TASKS]={{"LEDON",LED_ON},{"LEDOFF",LED_OFF},{"SERVOON",Servo_Set_Angle},{"SERVOOFF",Servo_Off},
{"RELAYON",Relay_On},{"RELAYOFF",Relay_Off}};
	
//u8 ar[][ARRAY_SIZE]={{"YELLOW_GREEN"},{"RED_BULE"},{"GREEN_PINK"},{"PINK_ORANGE"},{"STEEL_BLACK"},{"BUKESKY_BLACK"}};
RGB_t CONVERT[Number_OF_TASKS]={{"YELLOW_GREEN",Show_off},{"RED_BULE",Show_off},{"GREEN_PINK",Show_off},{"PINK_ORANGE",Show_off},
{"STEEL_BLACK",Show_off},{"BUKESKY_BLACK",Show_off}};
		
/******************************************************************************************************************************************/
u8 index;
u8 check_string(u8 *Urat_str)
{
	u8 i,j,f1=0;
	for(i=0;i<Number_OF_TASKS;i++)
	{
		for(j=0;j<ARRAY1_SIZE;j++)
		{
			if(arr[i][j]!=Urat_str[j])
			{
				f1=1;
				break;
			}
		}
			if(f1==0)
			{
				index=i;
				return 1;
			}
			else if(f1==1)
			{
				f1=0;
			}
	}
	return 0;
	
}

void Split_String_Tasks(u8 *New_Str, u8 *num)
{
	u8 i;
	*num=0;
	
	for(i=0;i<ARRAY1_SIZE;i++)
	{
		if(arr[index][i]!='_')
		{
			New_Str[i]=arr[index][i];
		}
		if(arr[index][i]>='0'  &&  arr[index][i]<='9')
		{
			*num=*num*10+(arr[index][i]-'0');
		}
	}
	
}
void Split_String_RGB(u8 *first_Str, u8 *second_str)
{
	u8 i,f=0,j;
	for(i=0;i<ARRAY1_SIZE;i++)
	{
		if(arr[index][i]!='_')
		{
			if(f==0)
			{
				first_Str[i]=arr[index][i];
			}
			else
			{
				second_str[j]=arr[index][i];
				j++;
			}
		}
		else
		{
			f=1;
		}
	}
}

void Turn_ON_Task(u8 *New_Str, u8 num)
{
	u8 i,j,f=0;
	for(i=0;i<Number_OF_TASKS;i++)
	{
		for(j=0;TASKS[i].str[j];j++)
		{
			if(New_Str[j]!=TASKS[i].str[j])
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			TASKS[i].fptr(num);
			break;
		}
		else
		{
			f=0;
		}
	}
}