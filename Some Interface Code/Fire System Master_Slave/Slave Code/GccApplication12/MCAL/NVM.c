/*
 * NVM.c
 *
 * Created: 1/4/2023 9:27:44 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utiles.h"
#include "NVM.h"
void NVM_Write(u16 uiAddress,u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE));
	/* Set up address and Data Registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMPE */
	EECR |= (1<<EEMPE);
	/* Start eeprom write by setting EEPE */
	EECR |= (1<<EEPE);
	
}
u8 NVM_Read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEPE));
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from Data Register */
	return EEDR;
}
void NVM_Interput_ON(void)
{
	SET_BIT(EECR,EERIE);
}
void NVM_Interput_Off(void)
{
	CLR_BIT(EECR,EERIE);
}
