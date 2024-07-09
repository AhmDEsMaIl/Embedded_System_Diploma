/*
 * Temp_Filter.h
 *
 * Created: 12/16/2022 2:53:35 PM
 *  Author: ahmed
 */ 


#ifndef TEMP_FILTER_H_
#define TEMP_FILTER_H_

void Temp_FilterInit(void);

void Temp_FilterRunnable(void);

u16 Temp_FilterGetter(void);


#endif /* TEMP_FILTER_H_ */