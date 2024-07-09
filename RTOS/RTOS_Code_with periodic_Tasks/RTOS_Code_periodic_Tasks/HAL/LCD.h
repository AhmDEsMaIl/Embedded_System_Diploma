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

#define  RS  PINC0_PR
#define  EN  PINC2_PR


#define  LCD_PORT   PD


#define  D7   PIND7_PR
#define  D6   PIND6_PR
#define  D5   PIND5_PR
#define  D4   PIND4_PR


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
void LCD_WriteString(s8*str);
void LCD_WriteBinary_1(u8 num);
void LCD_WriteNumberBinary_2(u8 num);
void LCD_WriteNumberBinary_3(u8 num);
void LCD_WriteHex(u8 num);
void LCD_CreateCharacter(u8*pattern,u8 address);
void LCD_WriteNumber_4D(u16 num);
void LCD_WriteNumber_SetCursor(u8 line ,u8 x,s64 num);
/** line 0:1  cell 0:15 **/
void LCD_SetCursor_1(u8 line ,u8 cell);
void LCD_SetCursor_2(u8 Line, u8 x);



//void LCD_SetCursorString(u8 line,u8 cell,u8*str);




#endif /* LCD_H_ */