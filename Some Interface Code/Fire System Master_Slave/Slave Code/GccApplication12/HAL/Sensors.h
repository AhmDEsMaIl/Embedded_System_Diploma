/*
 * Sensors.h
 *
 * Created: 12/9/2022 4:40:45 AM
 *  Author: ahmed
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_


#define LM35_CH           CH_0
#define MPX4115_CH        CH_0



u16 Temp_Read(void);
u16 PRESS_Read(void);



#endif /* SENSORS_H_ */