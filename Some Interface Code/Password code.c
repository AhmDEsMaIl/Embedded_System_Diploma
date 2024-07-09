#include "MemMap.h"
#include "Utiles.h"
#include "StdTypes.h"
#include "DIO_interface.h"
#include "Motor_interface.h"
#include "Motor_cfg.h"
#include "LCD.h"
#include "ADC.h"
#include "LED.h"
#include "Sensors.h"
#include "Temp_Filter.h"
#include "Buzzer.h"
#include "Interrupt.h"
#include "NVM.h"
#include <util/delay.h>
#define CPU_F     8000000
#define Global_Enable   sei
#include "Keypad.h"
u16 pass=0,D=1000;
int main(void)
{
	/*Replace with your application code */
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	Temp_FilterInit();
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_Enable(EX_INT1);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);
	LCD_WriteString("inter");
	Global_Enable();
	u16 passenter=0;
	u8 k=0,num=0,i=0,lock=0,c,f2=0,f1=0,f3=1;
	pass=NVM_Read(0);
	f1=NVM_Read(3);
	while(1)
	{
		
		if(f1==1)
		{
			D=NVM_Read(2);
			LCD_SetCursor(1,2);
			LCD_WriteNumber(D);
		}
		while(D<300)
		{
			if(D==0 ||f3==1)
			{
				LCD_WriteString("                   ");
				LCD_SetCursor(0,0);
				LCD_WriteString("WAI 5 MIM TR AGN");
				LED_ON(2);
				f3=0;
			}
			_delay_ms(10);
			if(!(D%60))
			{
				NVM_Write(2,D);
				LCD_SetCursor(1,0);
				LCD_WriteNumber(D/60);
				LCD_WriteString("MIN Gone");
				_delay_ms(1000);
			}
			if(D==299)
			{
				f1=0;
				lock=0;
				LED_OFF(2);
				NVM_Write(3,0);
				LCD_SetCursor(1,12);
				LCD_WriteNumber(D);
				LCD_SetCursor(1,0);
				LCD_WriteNumber(5);
				LCD_WriteString("MIN Gone");
				_delay_ms(1000);
				
			}
			++D;
		}
		if(f2==0)
		{
		LCD_Clear();
		LCD_SetCursor(0,0);
		LCD_WriteString("PLZ ENT PASS");
		f2=4;
		}
		if(f2==1)
		{
				LCD_Clear();
				LCD_SetCursor(0,0);
				LCD_WriteString("CHANGE PASS");
				f2=3;
		}
		k=KEYPAD_GetKey();
		if(k!=NO_KEY)
		{
			if(k>='0'&& k<='9')
			{
				num=num*10+(k-'0');
				passenter=num;
				LCD_SetCursor(1,i);  // i is variable to set by 5 to make LCD began on cell num 5 and increase with every char
				LCD_WriteChar('*');
				i++;
			}
			if(k=='=')
			{
				if(f2==4)
				{
				if(pass==passenter)
				{
					LED_ON(1);
					LCD_SetCursor(0,0);
					LCD_WriteString("PASS CORRECT");
					_delay_ms(500);
					LCD_SetCursor(1,0);
					LCD_WriteString("                  ");
					num=0;
					LED_OFF(1);
					i=0;
					lock=0;
					f2=0;
				}
				else
				{
					LED_ON(2);
					LCD_SetCursor(0,0);
					LCD_WriteString("PASS NOT CORR");
					_delay_ms(500);
					LCD_SetCursor(1,0);
					LCD_WriteString("                  ");
					num=0;
					i=0;
					LED_OFF(2);
					++lock;
					f2=0;
				}	
		      }
			  if(f2==3)
			  {
				  NVM_Write(0,passenter);
				  LCD_Clear();
				  LCD_SetCursor(0,0);
				  LCD_WriteString("   Done   ");
				  LCD_SetCursor(1,0);
				  LCD_WriteString("PLZ REST PROGRAM");
				  num=0;
				  i=0;
				  f2=0;
				  while(1);
			  }
			}
			if(k=='c')
			{
				f2=1;
			}
			}
		if(lock==3)
		{
			D=0;
			NVM_Write(3,1);
			c=NVM_Read(3);
			LCD_SetCursor(1,0);
			LCD_WriteNumber(c);
		}
		
	}
}