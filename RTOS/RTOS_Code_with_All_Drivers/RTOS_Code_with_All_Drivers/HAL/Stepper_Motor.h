/*
 * Stepper_Motor.h
 *
 * Created: 2/17/2023 7:38:45 PM
 *  Author: ahmed
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

/**************************************************************/
#define COLI1A       PINC4_PR 
#define COLI1B       PINC5_PR 
#define COLI2A       PINC6_PR
#define COLI2B       PINC7_PR

#define Step_Size    10

#define DELAY         10
/*************************************************************/


void Stepper_Bipoler_CW(void);
void Stepper_Bipoler_CCW(void);
void Stepper_Unipoler_CW(void);
void Stepper_Unipoler_CCW(void);
void Stepper_Unipoler_CW_HS(void);
void Stepper_Unipoler_CCW_HS(void);
u8 Stepper_Unipoler_CW_By_Rot(u8 Rot); // if return 1 means that step size is numb of rotates will be correct else if return 0 mean that rot will 
                                       // increase or decrease rotates so must change value step size 
u8 Stepper_Unipoler_CW_Hs_By_angle(u16 Angle);

#endif /* STEPPER_MOTOR_H_ */