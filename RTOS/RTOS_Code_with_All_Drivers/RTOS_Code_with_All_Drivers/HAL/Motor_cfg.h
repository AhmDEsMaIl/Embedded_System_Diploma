/*
 * Motor_cfg.h
 *
 * Created: 11/4/2022 11:36:49 PM
 *  Author: ahmed
 */ 

#include "DIO_interface.h"
#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_

#define bottom1                PIND2_PR

#define  bottom2               PIND3_PR

#define relay1pin               PINC7_PR

#define relay2pin               PINC3_PR

#define  NUMBER_MOTORS   2

/******************PIN config ***********************************/

#define  M1_IN1   PIND7_PR
#define  M1_IN2   PINC4_PR

#define  M2_IN1   PIND7_PR
#define  M2_IN2   PINC4_PR

#define  M3_IN1   PIND7_PR
#define  M3_IN2   PINC4_PR

#define  M4_IN1   PIND7_PR
#define  M4_IN2   PINC4_PR


#endif /* MOTOR_CFG_H_ */