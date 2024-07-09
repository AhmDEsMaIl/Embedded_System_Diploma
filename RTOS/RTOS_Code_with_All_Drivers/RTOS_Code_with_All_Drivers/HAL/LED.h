/*
 * LED.h
 *
 * Created: 12/9/2022 1:25:00 AM
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_


#define _1_LED_Pin    PINC4_PR
#define _2_LED_Pin    PINC5_PR
#define _3_LED_Pin    PINC6_PR
#define _4_LED_Pin    PINB3_PR
#define _5_LED_Pin    PINC2_PR
#define _6_LED_Pin    PINB5_PR
#define _7_LED_Pin    PINB6_PR
#define _8_LED_Pin    PINB7_PR


void LED_ON(u32 LED_Numb);
void LED_OFF(u32 LED_Numb);

#endif /* LED_H_ */