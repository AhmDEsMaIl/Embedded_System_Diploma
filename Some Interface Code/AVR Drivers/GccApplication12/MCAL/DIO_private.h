/*
 * DIO_private.h
 *
 * Created: 11/2/2022 4:23:14 PM
 *  Author: ahmed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];
 void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);



#endif /* DIO_PRIVATE_H_ */