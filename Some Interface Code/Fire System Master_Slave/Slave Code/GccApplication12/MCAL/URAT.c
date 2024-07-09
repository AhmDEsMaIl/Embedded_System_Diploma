/*
 * URAT.c
 *
 * Created: 2/24/2023 10:22:54 PM
 *  Author: ahmed
 */ 
#include "URAT.h"
#include "Utiles.h"
#include "StdTypes.h"
#include "MemMap.h"
static void (*URAT_RX_Fptr) (void)=NULLPTR;
static void (*URAT_TX_Fptr) (void)=NULLPTR;
void URAT_INIT(void)
{
	/*Baud rate 9600 Clock 8MHZ*/
	UBRRL=51;
	/*Normal Speed*/
	CLR_BIT(UCSRA,U2X);
	/*frame*/
	/*8 Bit Data 1 Stop No parity*/
	/*Enable*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}
void URAT_Send_Data(u8 Data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=Data;
}
u8 URAT_Recieve_Data(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}
u8 URAT_RecievePerodic(u8*pData)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*pData=UDR;
		return 1;
	}
	return 0;
}
u8 Frame_SW(u8 data)   //8 bit data 1 strat and 1 stop and one even parity
{
	u16 frame=0,c=0;
	//8 bit data
	frame=data| frame;
	frame=frame<<1;
	//one even parity
	for(int i=0;i<8;i++)
	{
		if(READ_BIT(data,i))
		{
			c++;
		}
	}
	if(c%2==1)
	{
		frame=frame| 0x200;
	}
	//1 stop
	frame=frame| 0x400;
}


void UART_SendStringCheckSum(u8*str){	u8 i,l;	u16 sum=0;	for (l=0;str[l];l++);	UART_SendData(l);	for (l=0;str[l];l++)	{		UART_SendData(str[l]);		sum=sum+str[l];	}	UART_SendData((u8)sum);	UART_SendData((u8)(sum>>8));}
/*void UART_ReceiveStringCheckSum(u8*str)
{
	u8 l=UART_receiveData();
	u8 i=0,*p;
	u8 arr={0};
	str[i]=UART_recevieData();
	for (;str[i];i++)	{		str[i]=UART_recevieData();			}
	if(c!=l)
	{
		return 0;
	}
	arr[0]=UART_recevieData();
	arr[1]=UART_recevieData();
	
}*/
void URAT_sendNoBlock(u8 data)
{
	UDR=data;
}
void URAT_ReceiveNoBlock(u8 data)
{
	return UDR;
}
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}
void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}
void UART_RX_SetCallBack(void(*localfptr)(void))
{
	URAT_RX_Fptr=localfptr;
}
void UART_TX_SetCallBack(void(*LocalFptr)(void))
{
	URAT_TX_Fptr=LocalFptr;
}
ISR(UART_RX_vect)
{
	if(URAT_RX_Fptr!=NULLPTR)
	{
		URAT_RX_Fptr();
	}
}
ISR(UART_TX_vect)
{
	if(URAT_TX_Fptr!=NULLPTR)
	{
		URAT_TX_Fptr();
	}
}


