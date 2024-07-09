/*
 * SPI.c
 *
 * Created: 3/7/2023 10:03:56 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "SPI.h"
#define F_CPU     8000000
#include <util/delay.h>
void SPI_Init(SPIMode_type mode)
{
	if(mode==Master)
	{
		//clock 2Mhz
		SET_BIT(SPCR_PR,MSTR_PR);
	}
	else
	{
		CLR_BIT(SPCR_PR,MSTR_PR);
	}
	// SPI Enable
	SET_BIT(SPCR_PR,SPE_PR);
}
u8 SPI_SendReceieve(u8 data)
{
	SPDR_PR=data;
	while(!READ_BIT(SPSR_PR,SPIF_PR));
	return  SPDR_PR;
}
u8 SPI_Receieveperodic(u8 *pdata)
{
	if(READ_BIT(SPSR_PR,SPIF_PR))
	{
		*pdata=SPDR_PR;
		return 1;
	}
	return 0;
}
u8 SPI_Receieve()
{
	return SPDR_PR;
}
void SPI_Send(u8 data)
{
	 SPDR_PR=data;
}
u8 SPI_SendReceive_runtimeout(u8 data,u8*PreData,u16 Time)
{
	static u16 c=0;
	SPDR_PR=data;
	while(!READ_BIT(SPSR_PR,SPIF_PR)|| c<Time);
	{
		c++;
		_delay_us(1);
	}
	if(c<Time)
	{
		*PreData=SPDR_PR;
		return 1;
	}
	else
	{
		return 0;
	}
}