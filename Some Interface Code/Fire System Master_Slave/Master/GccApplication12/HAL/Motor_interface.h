/*
 * Motor_interface.h
 *
 * Created: 11/4/2022 11:35:47 PM
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

void Motor_on_relay1_cw(void);
void Motor_off_relay2_antiCw(void);
typedef enum{
	M1,
	M2,
	M3,
	M4,
	M5
}MOTOR_type;



void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);

void Motor_off_relay1_cw(void);
void Motor_on_relay2_antiCw(void);
void Motor_on_relay1_cw(void);
void Motor_off_relay2_antiCw(void);



void Motor_With_2_Bottom(DIO_Pin_type pin1,DIO_Pin_type pin2);


/*  speed from 0 to 100  %**/
void MOTOR_Speed(MOTOR_type motor,u8 speed);


#endif /* MOTOR_INTERFACE_H_ */