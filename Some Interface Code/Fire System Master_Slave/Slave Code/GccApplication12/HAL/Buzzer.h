/*
 * Buzzer.h
 *
 * Created: 12/16/2022 6:57:00 PM
 *  Author: ahmed
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
////////////////////////////////////////////////////CONG//////////////////////////////////////////////////////////////


#define Buzzer_Pin           PINB2

#define Relay_1_Pin          PINC4

#define Relay_2_Pin          PINC3

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Buzzer_On (void);
void Buzzer_OFF (void);

void Relay_On (u32 num);
void Relay_Off (u32 num);



#endif /* BUZZER_H_ */