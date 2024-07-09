/*
 * Sensors.h
 *
 * Created: 12/9/2022 4:40:45 AM
 *  Author: ahmed
 */ 

#include "DIO_interface.h"
#ifndef SENSORS_H_
#define SENSORS_H_


#define LM35_CH               CH_1
#define MPX4115_CH            CH_0
#define MQ_2_Pin              PINF0
typedef enum
{
    Smoke=0,
	NO_somke
}MQ_2;

MQ_2 MQ_2_Read();

u16 Temp_Read(void);
u16 PRESS_Read(void);



#endif /* SENSORS_H_ */