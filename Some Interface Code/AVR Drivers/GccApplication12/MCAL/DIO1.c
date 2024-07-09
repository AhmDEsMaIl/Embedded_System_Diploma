/*
 * DIO1.c
 *
 * Created: 11/2/2022 4:20:33 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utiles.h"
#include "DIO_interface.h"
#include "DIO_private.h"


 void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			case PE:
			SET_BIT(DDRE,pin_num);
			CLR_BIT(PORTE,pin_num);
			break;
			case PF:
			SET_BIT(DDRF,pin_num);
			CLR_BIT(PORTF,pin_num);
			break;
			case PG:
			SET_BIT(DDRG,pin_num);
			CLR_BIT(PORTG,pin_num);
			break;
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			case PE:
			CLR_BIT(DDRE,pin_num);
			CLR_BIT(PORTE,pin_num);
			break;
			case PF:
			CLR_BIT(DDRF,pin_num);
			CLR_BIT(PORTF,pin_num);
			break;
			case PG:
			CLR_BIT(DDRG,pin_num);
			CLR_BIT(PORTG,pin_num);
			break;
		}
		break;
		
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
			case PE:
			CLR_BIT(DDRE,pin_num);
			SET_BIT(PORTE,pin_num);
			break;
			case PF:
			CLR_BIT(DDRF,pin_num);
			SET_BIT(PORTF,pin_num);
			break;
			case PG:
			CLR_BIT(DDRG,pin_num);
			SET_BIT(PORTG,pin_num);
			break;
		}
		break;
	}
	
}



void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	
	
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			
			SET_BIT(PORTD,pin_num);
			break;
			
			case PE:
			
			SET_BIT(PORTE,pin_num);
			break;
			case PF:
			
			SET_BIT(PORTF,pin_num);
			break;
			case PG:
			
			SET_BIT(PORTG,pin_num);
			break;
		}
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			
			CLR_BIT(PORTD,pin_num);
			break;
			
			case PE:
			
			CLR_BIT(PORTE,pin_num);
			break;
			case PF:
			
			CLR_BIT(PORTF,pin_num);
			break;
			case PG:
			
			CLR_BIT(PORTG,pin_num);
			break;
		}
	}

}


DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	
	switch(port)
	{
		case PA:
		
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		
		volt=READ_BIT(PIND,pin_num);
		break;
		
		case PE:
		
		volt=READ_BIT(PINE,pin_num);
		break;
		case PF:
		
		volt=READ_BIT(PINF,pin_num);
		break;
		case PG:
		
		volt=READ_BIT(PING,pin_num);
		break;
	}
	
	return volt;
	
	
}

void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}

}
void DIO_TogglePin(DIO_Pin_type pin)
{
	//pin=pin^(1);
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	
	switch(port)
	{
		case PA:
		
		Toggle_BIT(PORTA,pin_num);
		break;
		case PB:
		
		Toggle_BIT(PORTB,pin_num);
		break;
		case PC:
		
		Toggle_BIT(PORTC,pin_num);
		break;
		case PD:
		
		Toggle_BIT(PORTD,pin_num);
		break;
		
		case PE:
		
		Toggle_BIT(PORTE,pin_num);
		break;
		case PF:
		
		Toggle_BIT(PORTF,pin_num);
		break;
		case PG:
		
		Toggle_BIT(PORTG,pin_num);
		break;
	}
}
void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		
		PORTA=value;
		break;
		case PB:
		
		PORTB=value;
		break;
		case PC:
		
		PORTC=value;
		break;
		case PD:
		
		PORTD=value;
		break;
		
		case PE:
		
		PORTE=value;
		break;
		case PF:
		
		PORTF=value;
		break;
		case PG:
		
		PORTG=value;
		break;
	}
}
u8 DIO_ReadPort(DIO_Port_type port)
{
	u8 value=0;
	switch(port)
	{
		case PA:
		
		value=PINA0|(value>>0);
		value=PINA1|(value>>1);
		value=PINA2|(value>>2);
		value=PINA3|(value>>3);
		value=PINA4|(value>>4);
		value=PINA5|(value>>5);
		value=PINA6|(value>>6);
		value=PINA7|(value>>7);
		break;
		case PB:
		
		value=PINB0|(value>>0);
		value=PINB1|(value>>1);
		value=PINB2|(value>>2);
		value=PINB3|(value>>3);
		value=PINB4|(value>>4);
		value=PINB5|(value>>5);
		value=PINB6|(value>>6);
		value=PINB7|(value>>7);
		break;
		case PC:
		
		value=PINC0|(value>>0);
		value=PINC1|(value>>1);
		value=PINC2|(value>>2);
		value=PINC3|(value>>3);
		value=PINC4|(value>>4);
		value=PINC5|(value>>5);
		value=PINC6|(value>>6);
		value=PINC7|(value>>7);
		break;
		case PD:
		
		value=PIND0|(value>>0);
		value=PIND1|(value>>1);
		value=PIND2|(value>>2);
		value=PIND3|(value>>3);
		value=PIND4|(value>>4);
		value=PIND5|(value>>5);
		value=PIND6|(value>>6);
		value=PIND7|(value>>7);
		break;
		case PE:
		
		value=PINE0|(value>>0);
		value=PINE1|(value>>1);
		value=PINE2|(value>>2);
		value=PINE3|(value>>3);
		value=PINE4|(value>>4);
		value=PINE5|(value>>5);
		value=PINE6|(value>>6);
		value=PINE7|(value>>7);
		break;
		case PF:
		
		value=PINF0|(value>>0);
		value=PINF1|(value>>1);
		value=PINF2|(value>>2);
		value=PINF3|(value>>3);
		value=PINF4|(value>>4);
		value=PINF5|(value>>5);
		value=PINF6|(value>>6);
		value=PINF7|(value>>7);
		break;
		case PG:
		
		value=PING0|(value>>0);
		value=PING1|(value>>1);
		value=PING2|(value>>2);
		value=PING3|(value>>3);
		value=PING4|(value>>4);
		value=PING5|(value>>5);
		value=PING6|(value>>6);
		value=PING7|(value>>7);
		break;
	}
	
}
