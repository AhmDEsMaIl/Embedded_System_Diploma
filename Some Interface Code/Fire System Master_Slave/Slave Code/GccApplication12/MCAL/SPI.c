/*
 * SPI.c
 *
 * Created: 3/7/2023 10:03:56 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utiles.h"
#include "SPI.h"
void SPI_Init(SPIMode_type mode)
{
	if(mode==Master)
	{
		//clock 2Mhz
		SET_BIT(SPCR,MSTR);
	}
	else
	{
		CLR_BIT(SPCR,MSTR);
	}
	// SPI Enable
	SET_BIT(SPCR,SPE);
}
u8 SPI_SendReceieve(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return  SPDR;
}
u8 SPI_Receieveperodic(u8 *pdata)
{
	if(READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}
u8 SPI_Receieve()
{
	return SPDR;
}
void SPI_Send(u8 data)
{
	SPDR=data;
}