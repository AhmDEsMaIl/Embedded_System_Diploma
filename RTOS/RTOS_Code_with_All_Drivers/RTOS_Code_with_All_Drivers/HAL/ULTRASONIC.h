/*
 * ULTRASONIC.h
 *
 * Created: 2/14/2023 10:24:44 PM
 *  Author: ahmed
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#define  US1   PIND0_PR
#define  US2   PIND1_PR
#define  US3   PIND2_PR
#define  US4   PIND3_PR
#define Numb_US   4
typedef   DIO_Pin_type ULTRASONIC_type;

typedef enum{
	ULTRASONIC_1=PIND2_PR,
	ULTRASONIC_2=PIND6_PR,
	ULTRASONIC_3=PIND3_PR,
	ULTRASONIC_4=PIND5_PR,
}ULTRASONIC_type2;



void ULTRASONIC_Init(void);


u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16*pdistance);
u16 ULTRASONIC_GetDistance2(ULTRASONIC_type2 us);

void Four_UltraSonic_Init(void);
void Four_UltraSonic_Runnable(void);
u16 Four_UltraSonic_get_distance(ULTRASONIC_type us);





#endif /* ULTRASONIC_H_ */