/*
 * Stepper_Motor.h
 *
 * Created: 2/18/2023 5:02:04 PM
 *  Author: ahmed
 */ 


#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

/**************************************************************/
#define COLI1A       PIND0
#define COLI1B       PIND1
#define COLI2A       PIND2
#define COLI2B       PIND3

#define Step_Size    10

#define DELAY         10
/*********************************************************/
void Interpurt_Stepper(void);

u8 Stepper_Unipoler_CW_Interput(void);
void Stepper_Bipoler_CCW(void);
void Stepper_Unipoler_CW(void);
void Stepper_Unipoler_CCW(void);
void Stepper_Unipoler_CW_HS(void);
void Stepper_Unipoler_CCW_HS(void);
void Stepper_Unipoler_CW_OFF(void);
u8 Stepper_Unipoler_CW_By_Rot(u8 Rot); // if return 1 means that step size is numb of rotates will be correct else if return 0 mean that rot will
// increase or decrease rotates so must change value step size
u8 Stepper_Unipoler_CW_Hs_By_angle(u16 Angle);




#endif /* STEPPER_MOTOR_H_ */