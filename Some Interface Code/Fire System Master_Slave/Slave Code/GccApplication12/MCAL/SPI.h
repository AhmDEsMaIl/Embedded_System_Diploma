/*
 * SPI.h
 *
 * Created: 3/7/2023 10:04:19 PM
 *  Author: ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_

typedef enum
{
	Master,
	Slave
	}SPIMode_type;
void SPI_Init(SPIMode_type mode);
u8 SPI_SendReceieve(u8 data);
u8 SPI_Receieveperodic(u8 *pdata);
u8 SPI_Receieve();
void SPI_Send(u8 data);
#endif /* SPI_H_ */