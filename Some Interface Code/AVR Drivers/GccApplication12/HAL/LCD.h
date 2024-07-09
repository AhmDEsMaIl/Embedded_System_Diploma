/*
 * LCD.h
 *
 * Created: 11/13/2022 10:10:23 PM
 *  Author: ahmed
 */ 

#ifndef LCD_H_
#define LCD_H_

#define  _4_Bit     1
#define  _8_Bit     2

#define LCD_MODE     _4_Bit

#define  RS  PINB1
#define  EN  PINB0


#define  LCD_PORT   PD


#define  D7   PIND7
#define  D6   PIND6
#define  D5   PIND5
#define  D4   PIND4


typedef enum
{
	Eight_BiT_Mode=0,
	Four_Bit_Mode
}LCD_Mode;

void LCD_Init(void);

void LCD_Clear(void);
void LCD_Clear_With_Began (u8 line ,u8 cell,u8 num);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(c8*str);

void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

void LCD_WriteNumber_4D(u16 num);

/** line 0:1  cell 0:15 **/
void LCD_SetCursor(u8 line ,u8 cell);



//void LCD_SetCursorString(u8 line,u8 cell,u8*str);




#endif /* LCD_H_ */