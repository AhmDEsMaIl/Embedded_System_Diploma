/*
 * String_Service.h
 *
 * Created: 10/10/2023 9:25:53 PM
 *  Author: ahmed
 */ 


#ifndef STRING_SERVICE_H_
#define STRING_SERVICE_H_
#include "StdTypes.h"

u16 String_length(u8 *str);
void String_revse (char *str);
u16 String_Convert_String_INT(char *str);
char String_IS_String_Is_mirror (u8 *str);
void String_Convert_INT_string(u8 *str,u16 n);
void String_Convert_Float_string (double num, u8 * str);





#endif /* STRING_SERVICE_H_ */