/*
 * Fire_System.h
 *
 * Created: 2/27/2023 12:46:40 AM
 *  Author: ahmed
 */ 


#ifndef FIRE SYSTEM_H_
#define FIRE SYSTEM_H_
#define High_Temp_thersold      500
#define Low_Temp_thersold       450

void INIT(void);
void LDR_ON(void);
void LCD_INIT(void);
void TEMP_PRESS_CRITICAL(void);
void High_TEMP_HIGH_PRESS(void);
void High_TEMP_LOW_PRESS(void);
void LOW_TEMP(void);
void High_PRESS(void);
void f7(void);
void f9(void);
void change_pass(void);
#endif /* FIRE SYSTEM_H_ */