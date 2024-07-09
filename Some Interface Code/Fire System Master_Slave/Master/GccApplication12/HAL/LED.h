/*
 * LED.h
 *
 * Created: 12/9/2022 1:25:00 AM
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_


#define _1_LED_Pin    PINC4
#define _2_LED_Pin    PINC5
#define _3_LED_Pin    PINC6
#define _4_LED_Pin    PINB3
#define _5_LED_Pin    PINC2
#define _6_LED_Pin    PINB5
#define _7_LED_Pin    PINB6
#define _8_LED_Pin    PINB7


void LED_ON(u32 LED_Numb);
void LED_OFF(u32 LED_Numb);

#endif /* LED_H_ */