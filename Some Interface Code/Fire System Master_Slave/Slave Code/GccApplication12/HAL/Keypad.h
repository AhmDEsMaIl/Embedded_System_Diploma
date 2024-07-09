/*
 * Keypad.h
 *
 * Created: 11/30/2022 12:29:04 AM
 *  Author: ahmed
 */ 
/*
 * KeyPad.h
 *
 * Created: 3/14/2021 1:47:11 PM
 *  Author: khaliid
 */ 


#ifndef Keypad_H_
#define Keypad_H_

#include  "StdTypes.h"
#include "DIO_Interface.h"

/*************************Pin config*******************************/

#define  FIRST_IN  PINC0
#define  FIRST_OUT PINB4

#define ROWS 4
#define COLS 4
#define NO_KEY '.'
/*****************************************************************/


u8 KEYPAD_GetKey(void);
void KEYPAD_Init(void);
u32 KEYPAD_DEC(u8 k);
void KEYPAD_BIN_Display(u8 *arr,u8 k,u8 size);
u16 KEYPAD_BIN_T_DEC_CONV(u8 *arr,u8 size);
u32 KEYPAD_HEX();
u32 KEYPAD_HEX_T_DEC_CONV(u8 *arr,u8 k,u8 size);
#endif /* Keypad */