/*
 * EEPROM.c
 *
 * Created: 1/4/2023 5:45:53 AM
 *  Author: ahmed
 */
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "EEPROM.h"
void EEPROM_Write(u16 uiAddress,u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR_PR & (1<<EEWE_PR));
	/* Set up address and Data Registers */
	EEAR_PR = uiAddress;
	EEDR_PR = ucData;
	/* Write logical one to EEMPE */
	EECR_PR |= (1<<EEMWE_PR );
	/* Start eeprom write by setting EEPE */
	EECR_PR |= (1<<EEWE_PR);	
	
}
u8 EEPROM_Read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR_PR & (1<<EEWE_PR));
	/* Set up address register */
	EEAR_PR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR_PR |= (1<<EERE_PR);
	/* Return data from Data Register */
	return EEDR_PR;
}