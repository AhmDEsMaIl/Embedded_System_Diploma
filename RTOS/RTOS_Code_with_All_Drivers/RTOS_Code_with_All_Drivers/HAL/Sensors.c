/*
 * Sensors.c
 *
 * Created: 12/9/2022 4:47:44 AM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "ADC.h"
#include "Sensors.h"
#define F_CPU     8000000
#include <util/delay.h>
u16 Temp_Read(void)
{
	u16 volt=ADC_Read_volt(LM35_CH);
	u16 Temp =volt;
	return Temp;
}


u16 PRESS_Read(void){	u16 adc,press;	adc=ADC_Read(MPX4115_CH);		press=(((u32)1000*(adc-55))/921)+150;	return press;}





float LPGCurve[3] = {2.3,0.20,-0.45};   //two points from LPG curve are taken point1:(200,1.6) point2(10000,0.26)
//take log of each point (lg200, lg 1.6)=(2.3,0.20)  (lg10000,lg0.26)=(4,-0.58)
//find the slope using these points. take point1 as reference
//data format:{ x, y, slope};


float SmokeCurve[3] ={2.3,0.53,-0.43};  //two points from smoke curve are taken point1:(200,3.4) point2(10000,0.62)
//take log of each point (lg200, lg3.4)=(2.3,0.53)  (lg10000,lg0.63)=(4,-0.20)
//find the slope using these points. take point1 as reference
//data format:{ x, y, slope};

// sensor and load resistor forms a voltage divider. so using analog value and load value
// we will find sensor resistor.

u16 ResistanceCalculation(u16 raw_adc){
	return ( (1023-raw_adc)/raw_adc);   // we will find sensor resistor.
}

u16 SensorCalibration(){

	int i;                                   // This function assumes that sensor is in clean air.
	u16 val=0;
	
	for (i=0;i<50;i++){                   //take multiple samples and calculate the average value
		val += ResistanceCalculation(ADC_Read(CH_0));
		_delay_ms(50);
	}

	val = val/50;
	val = val/RO_CLEAN_AIR_FACTOR;           //divided by RO_CLEAN_AIR_FACTOR yields the Ro according to the chart in the datasheet
	
	return val;
}

float ReadSensor(){
	int i;
	float rs=0;

	for (i=0;i<5;i++) {                                 // take multiple readings and average it.
		rs += ResistanceCalculation(ADC_Read(CH_0));   // rs changes according to gas concentration.
		_delay_ms(50);
	}

	rs = rs/5;
	
	return rs;
}

int GetGasPercentage(float rs_ro_ratio, int gas_id){
	if ( gas_id == LPG ) {
		return GetPercentage(rs_ro_ratio,LPGCurve);
	}
	else if( gas_id == SMOKE ) {
		return GetPercentage(rs_ro_ratio,SmokeCurve);
	}

	return 0;
}

//Using slope,ratio(y2) and another point(x1,y1) on line we will find
// gas concentration(x2) using x2 = [((y2-y1)/slope)+x1]
// as in curves are on logarithmic coordinate, power of 10 is taken to convert result to non-logarithmic.

int  GetPercentage(float rs_ro_ratio, float *curve){
	return (pow(10,( ((log(rs_ro_ratio)-curve[1])/curve[2]) + curve[0])));
}