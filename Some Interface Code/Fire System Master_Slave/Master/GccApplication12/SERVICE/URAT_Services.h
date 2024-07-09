/*
 * URAT_Services.h
 *
 * Created: 2/28/2023 7:32:08 PM
 *  Author: ahmed
 */ 

#include "StdTypes.h"

#ifndef URAT_SERVICES_H_
#define URAT_SERVICES_H_

typedef enum
{
	LITTLE,
	BIG
}Endian;
#define STACK_FULL     0
#define STACK_DONE     1
#define STACK_EMPTY   -1
#define STACK_SIZE    3


u8 push(u8 data);
u8  pop(u8 *pdata);
void URAT_SendString(u8 *str);
void URAT_Stack_push();
u8 URAT_Stack_pop();
void Stack_In();
void Stack_INT();

void URAT_ReceiveString(u8 *str);
void URAT_SendNumber(u32 numb);
u32 URAT_ReceiveNumber(void);
Endian Check_Endian(void);
u32 Endian_Convert_u32(u32 num);
void URAT_SendStringchecksum(u8 *str);
u8 URAT_ReceiveStringchecksum(u8 *str);
void URAT_SendStringAshync(u8* str);
void TX_Fun(void);

#endif /* URAT_SERVICES_H_ */