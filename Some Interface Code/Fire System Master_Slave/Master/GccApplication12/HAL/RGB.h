/*
 * RGB.h
 *
 * Created: 2/11/2023 5:39:02 PM
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#ifndef RGB_H_
#define RGB_H_


typedef enum
{
	Red=0,
	Green,
	Bule,
	Orange,
	Yellow,
	Pink,
	Brown,
	Grey,
	Purple,
	steel,
	Black_grey,
	olive,
	Amber,
	Black,
	SkyBule,
	Light_Green,
	Total_Colors
	
}Colors;

typedef struct col
{
	u8 Red;
	u8 Green;
	u8 Bule;
}RGB;


void  Set_RGB(Colors C);	
void red_to_green(void);
void switch_red_to_green(void);
void Show_off(Colors C1, Colors C2);
void Show_off_interput(void);
void Swang(void);
#endif /* RGB_H_ */