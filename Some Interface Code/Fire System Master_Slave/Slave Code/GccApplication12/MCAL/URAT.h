/*
 * URAT.h
 *
 * Created: 2/24/2023 10:22:33 PM
 *  Author: ahmed
 */ 

#include "StdTypes.h"
#ifndef URAT_H_
#define URAT_H_

void URAT_INIT(void);
void URAT_Send_Data(u8 Data);
u8 URAT_Recieve_Data(void);
u8 URAT_RecievePerodic(u8*pData);
u8 Frame_SW(u8 data);


void URAT_sendNoBlock(u8 data);
void URAT_ReceiveNoBlock(u8 data);
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void UART_RX_SetCallBack(void(*localfptr)(void));
void UART_TX_SetCallBack(void(*LocalFptr)(void));
#endif /* URAT_H_ */