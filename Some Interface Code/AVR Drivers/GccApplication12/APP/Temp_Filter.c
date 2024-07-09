/*
 * Temp_Filter.c
 *
 * Created: 12/16/2022 3:04:42 PM
 *  Author: ahmed
 */
 #include<util/delay.h>
 #define CPU_F     8000000
 #include "StdTypes.h"
 #include "Sensors.h"
 #include "Temp_Filter.h"
 static u8 arr[30]={0};
 static u16 Tempfiltered=0;
void Temp_FilterInit(void)
{
	Tempfiltered=Temp_Read();
}
void Temp_FilterRunnable(void)
{
	static u8 p=0;
	u8 f=0,i=0;
	u16 TotalTemp=0;
	arr[p]=Temp_Read();
	p++;
	if(f==0 && p==30)
	{
		for(i=0;i<30;i++)
		{
			TotalTemp+=arr[i];
			Tempfiltered=TotalTemp/30;
		}
		p=0;
	    f=1;
	}
	else if(f==1)
	{
		for(i=0;i<30;i++)
		{
			TotalTemp+=arr[i];
			Tempfiltered=TotalTemp/30;
		}
		if(p==30)
		{
			p=0;
		}
	}
	
	
}
u16 Temp_FilterGetter(void)
{
	return Tempfiltered;
}
