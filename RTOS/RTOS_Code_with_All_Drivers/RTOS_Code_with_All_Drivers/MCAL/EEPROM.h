/*
 * EEPROM.h
 *
 * Created: 10/10/2023 10:29:06 PM
 *  Author: ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
void EEPROM_Write(u16 uiAddress,u8 ucData);
u8 EEPROM_Read(u16 uiAddress);





#endif /* EEPROM_H_ */