/*
 * Tasks.h
 *
 *  Created on: May 7, 2021
 *      Author: Zack
 */

#ifndef MY_TASKS_H_
#define MY_TASKS_H_


#define  TASK1_PRIORITY (4) // 	High
#define  TASK2_PRIORITY (3) // 	Medium
#define  TASK3_PRIORITY (2) //	Low
#define  TASK4_PRIORITY (2) //	very Low

// Task  prototypes
 void Task1_LcdUpdate(void*pvParamter);
 void Task2_LcdUpdate(void*pvParamter);
 void Task3_Blink_L2(void*pvParamter);
 void Task4_Blink_L2(void*pvParamter);

void vApplicationIdleHook(void);




#endif /* MY_TASKS_H_ */




/*

// Defining each Task Priority
#define  TASK1_PRIORITY (2) // 	Low
#define  TASK2_PRIORITY (3) // 	Medium
#define  TASK3_PRIORITY (4) //	High

// Task  prototypes
 void Task1_LcdUpdate(void*pvParamter);
 void Task2_LcdUpdate(void*pvParamter);
 void Task3_Blink_L2(void*pvParamter);
 */
