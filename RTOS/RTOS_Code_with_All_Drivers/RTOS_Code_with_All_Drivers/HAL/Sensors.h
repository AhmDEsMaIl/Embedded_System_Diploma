/*
 * Sensors.h
 *
 * Created: 12/9/2022 4:40:45 AM
 *  Author: ahmed
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_


#define LM35_CH           CH_7
#define MPX4115_CH        CH_0


#define RL_VALUE (10)     //define the load resistance on the board, in kilo ohms
#define RO_CLEAN_AIR_FACTOR (9.83)  //(Sensor resistance in clean air)/RO,which is derived from the chart in datasheet
#define LPG (0)         // Gas identity no.
#define SMOKE (1)

int  GetPercentage(float, float *);
int GetGasPercentage(float , int);
float ReadSensor();
u16 ResistanceCalculation(u16 raw_adc);
u16 SensorCalibration();



u16 Temp_Read(void);
u16 PRESS_Read(void);



#endif /* SENSORS_H_ */