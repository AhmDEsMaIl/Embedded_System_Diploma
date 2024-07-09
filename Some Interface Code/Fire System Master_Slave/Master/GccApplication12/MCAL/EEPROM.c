/*
 * EEPROM.c
 *
 * Created: 1/4/2023 5:45:53 AM
 *  Author: ahmed
 */
#include "StdTypes.h"
#include "MemMap.h"
#include "Utiles.h"
#include "EEPROM.h"
void EEPROM_Write(u16 uiAddress,u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address and Data Registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);	
	
}
u8 EEPROM_Read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}