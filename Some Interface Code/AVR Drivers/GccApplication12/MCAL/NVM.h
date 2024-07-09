/*
 * NVM.h
 *
 * Created: 1/4/2023 9:28:07 PM
 *  Author: ahmed
 */ 


#ifndef NVM_H_
#define NVM_H_




void NVM_Write(u16 uiAddress,u8 ucData);
u8   NVM_Read(u16 uiAddress);
void NVM_Interput_ON(void);
void NVM_Interput_Off(void);
void EEPROM_SetCallBack(void(*LocalFptr)(void));



#endif /* NVM_H_ */