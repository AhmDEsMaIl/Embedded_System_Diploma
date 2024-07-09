/*
 * ULTRASONIC.h
 *
 * Created: 2/14/2023 10:24:44 PM
 *  Author: ahmed
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#define  US1   PIND0
#define  US2   PIND1
#define  US3   PIND2
#define  US4   PIND3
#define Numb_US   4
typedef   DIO_Pin_type ULTRASONIC_type;

typedef enum{
	ULTRASONIC_1=PIND2,
	ULTRASONIC_2=PIND6,
	ULTRASONIC_3=PIND3,
	ULTRASONIC_4=PIND5,
}ULTRASONIC_type2;



void ULTRASONIC_Init(void);


u8 ULTRASONIC_GetDistance(ULTRASONIC_type us,u16*pdistance);
u16 ULTRASONIC_GetDistance2(ULTRASONIC_type2 us);

void Four_UltraSonic_Init(void);
void Four_UltraSonic_Runnable(void);
u16 Four_UltraSonic_get_distance(ULTRASONIC_type us);





#endif /* ULTRASONIC_H_ */