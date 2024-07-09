/*
 * NVM.c
 *
 * Created: 1/4/2023 9:27:44 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "NVM.h"
void NVM_Write(u16 uiAddress,u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR_PR & (1<<EEWE_PR))
	;
	/* Set up address and Data Registers */
	EEAR_PR = uiAddress;
	EEDR_PR = ucData;
	/* Write logical one to EEMPE */
	EECR_PR |= (1<<EEMWE_PR );
	/* Start eeprom write by setting EEPE */
	EECR_PR |= (1<<EEWE_PR);
	
}
u8   NVM_Read(u16 uiAddress)
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
void NVM_Interput_ON(void)
{
	SET_BIT(EECR_PR,EERIE_PR);
}
void NVM_Interput_Off(void)
{
	CLR_BIT(EECR_PR,EERIE_PR);
}
