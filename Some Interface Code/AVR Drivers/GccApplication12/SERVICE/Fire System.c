/*
 * Fire_System.c
 *
 * Created: 2/27/2023 12:46:18 AM
 *  Author: ahmed
 */
 #include "StdTypes.h"
#include "LCD.h"
#include "ADC.h"
#include "LED.h"
#include "Sensors.h"
#include "Timer.h"
#include "Buzzer.h"
#include "Fire System.h"
#define Global_Enable   sei
#include "Keypad.h"
#include "Stepper_Motor.h"
#include "Interrupt.h"
#define F_CPU     16000000
#include <util/delay.h>
static u16 adc=0,adc_zero=0,num=0;
static  u16 Password=1953;
static u8 K=0,i=5,TOG=1;
 extern u16 T,P;
static u16 pass;
static volatile u16 NVM_interput_flag1,NVM_interput_flag2,n;
  static volatile u16 x ,numb;
 static u8 interput_timer,i;
static u16 local_pass,Switch_flag,temp, Enter_Change_Fun;
	
void f7()
{
	static u8 counter=0;
	if(NVM_interput_flag1==0)
	{
		NVM_Write(1,(u8)(x>>8));
		NVM_interput_flag1=1;
		LCD_SetCursor(1,10);
		LCD_WriteNumber(x);
		
	}
	else if (NVM_interput_flag1==1)
	{
		
		NVM_Interput_Off();
	}
	if(NVM_interput_flag2==0)
	{
		n=NVM_Read(1);
		NVM_interput_flag1=1;;
		
	}
	else
	{
		
		NVM_Interput_Off();
	}
	counter++;
	}
u8 f5=0;
u8 flag_fan=0;
u8 interrupt_switch_flag_pass=0;
u8 interrupt_switch_flag_LCD=0;
u8 interrupt_switch_flag_Fan=0;
u16 count2=0;
void f9()
{
	static u16 count=0;
	static u16 count1=0;
	//static u16 count2=0;
	if(count==1000&& interrupt_switch_flag_pass==1)
	{
		interput_timer=0;
		LCD_SetCursor(3,5);
		LCD_WriteString("Time Pass");
		LCD_Clear();
		interrupt_switch_flag_pass=0;
	}
	count++;
	if(count1==5000 && interrupt_switch_flag_LCD==1)
	{
		count1=0;
		f5=1;
		interrupt_switch_flag_LCD=0;
	}
	count1++;
	if(count2==70*(T/250) && interrupt_switch_flag_Fan==1)
	{
		count2=0;
		flag_fan=~flag_fan;
		interrupt_switch_flag_Fan=0;	
	}
	count2++;
}
void f10(void);
void f10(void)
{
	Toggle_BIT(PINC,0);
	LCD_SetCursor(0,0);
	LCD_WriteNumber(1);
}
void INIT()
{
// 	NVM_Write(0,0);
// 	NVM_Write(1,0);
	pass=1958;
	NVM_interput_flag1=0;
	NVM_interput_flag2=0;
	interput_timer=0;
	Switch_flag=0;
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	Temp_FilterInit();
	/*EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_Enable(EX_INT1);
	EXI_TriggerEdge(EX_INT0,RISING_EDGE);*/
 	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_INVERTING);
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_DISCONNECTED);
	Timer1_OCRB1Mode(OCRB_DISCONNECTED);
	TIMER2_Init(TIMER2_NORMAL_MODE,TIMER2_SCALER_8);
	TIMER2_OC2Mode(OC2_DISCONNECTED);
	/*Four_UltraSonic_Init();
	TIMER2_OV_InterruptEnable();*/
	TCNT0=0;
	Global_Enable();
	local_pass=pass;

	local_pass= NVM_Read(0);
	EEPROM_SetCallBack(f7);
	NVM_interput_flag2=0;
	NVM_interput_flag1=3;
	NVM_Interput_ON();
	local_pass=((local_pass) | (u16)(n<<8) );
	
	
	EXI_Enable(EX_INT0);
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_SetCallBack(EX_INT0,f10);
}
void LDR_ON()
{
		adc=ADC_Read(CH_2);
		adc_zero=(adc/4);
		OCR0=adc_zero;
		if(adc>1010)
		{
			OCR0=255;
		}
}
void change_pass()
{
	do
	{
	 LCD_SetCursor(2,0);
	 LCD_WriteNumber(local_pass);
	 LCD_SetCursor(3,0);
	 LCD_WriteNumber(numb);
	if(interput_timer==0)
	{
		K=KEYPAD_GetKey();
	}
	
	if(K!=NO_KEY && interput_timer==0)
	{
		
		if(K>='0' && K<='9')
		{
			numb=numb*10+(K-'0');
			LCD_SetCursor(1,i);  // i is variable to set by 5 to make LCD began on cell num 5 and increase with every char
			LCD_WriteChar('*');
			i++;
		}
		if(K=='c')
		{
			Enter_Change_Fun=1;
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("PLZ enter old pass");
			//i=5;
			numb=0;
			
		}
		
		if(K=='=' && Switch_flag==0)
		{
			LCD_Clear();
			i=5;				
			if(numb==local_pass)
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("PLZ enter new pass");
				K=0;
				numb=0;
				Switch_flag=1;
// 				LCD_SetCursor(1,0);
// 				LCD_WriteNumber(local_pass);
			}
			
			else
			{
				interrupt_switch_flag_pass=1;
				numb=0;
				K=0;
				Switch_flag=0;
				TIMER2_Init(TIMER2_NORMAL_MODE,TIMER2_SCALER_8);
				Timer2_OVF_SetCallBack(f9);
				TIMER2_OV_InterruptEnable();
				interput_timer=1;
				LCD_SetCursor(0,0);
				LCD_WriteString("pass wrong");
				LCD_SetCursor(1,0);
				LCD_WriteString("PLZenterwait1sec");
				_delay_ms(2000);
				LCD_Clear();
				Enter_Change_Fun=0;
				
			}
			
		}
		else if(K=='=' && Switch_flag==1)
		{
			i=5;
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("Pass Updated");
			LCD_SetCursor(1,0);
			LCD_WriteString("NEW Pass");
			x=numb;
			local_pass=0;
			local_pass=numb;
			NVM_Write(0,(u8)(x));
			NVM_interput_flag1=0;
			NVM_Interput_ON();
			Switch_flag=0;
			_delay_ms(1000);
			LCD_Clear();
			Enter_Change_Fun=0;
			
		

			
		}
	}
	}
	while(Enter_Change_Fun==1);
}
void LCD_INIT()
{
	if(Enter_Change_Fun==0)
	{
	Timer2_OVF_SetCallBack(f9);
	TIMER2_OV_InterruptEnable();	
	interrupt_switch_flag_LCD=1;
	if(f5==1)
	{
	T=Temp_Read();	
	LCD_SetCursor(0,0);
	LCD_WriteString("TEMP:");
	LCD_WriteNumber(T/10);    //  dividing by 10 to get first numb or tow which is ten num  or num before decimal point
	LCD_WriteChar('.');
	LCD_WriteNumber(T%10);    // remaindering by 10 to get fractional numb or numb after decimal point
	LCD_WriteChar('C');
	LCD_Clear_With_Began(0,0,3);
	f5=0;
	}
	}
}
void TEMP_PRESS_CRITICAL()
{
	LED_ON(1);            //   and Pass is correct and Big While(1) in main began again LED and Motor and Buzzer
	LED_OFF(2);           //    will still turn on  and program will enter small while(1) of If condition of Temp because
	LED_OFF(3);           //   Temp is more than 500 and Press is more than 575 so this condition will not let them turn  off
	Stepper_Unipoler_CW_OFF();// before Temp is less than 500 and press is less than 575
	Buzzer_OFF();
	Fan_On();
	LCD_SetCursor(3,0);
	LCD_WriteString("aaa");
}
void High_TEMP_HIGH_PRESS()
{
	TOG=1;
	Password=local_pass;
	LCD_Clear();   // clear LCD before enter FIRE State so i can write so free space in lCD to Put Pass '*'
	while(1&&TOG)  // and put FIRE in another place in LCD and put sentence of "PLZ Enter Pass " in Top of screen
	{
		
		K=KEYPAD_GetKey();  // to take return and check on it
		if(K!=NO_KEY)
		{
			if(K>='0' && K<='9')
			{
				num=num*10+(K-'0');
				LCD_SetCursor(1,i);  // i is variable to set by 5 to make LCD began on cell num 5 and increase with every char
				LCD_WriteChar('*');
				i++;
				
			}
			
		}
		LCD_SetCursor(0,0);
		LCD_WriteString("PLZ ENTER PASS /");
		LCD_SetCursor(1,0);
		LCD_WriteString("FIRE:");
		LED_ON(3);
		LED_OFF(1);
		LED_OFF(2);
		Stepper_Unipoler_CW_Interput();
		Buzzer_On();
		Fan_On();
		if((K=='=')&& (num==Password))
		{
			LCD_Clear();                   // clear LCD to can put my new sentence in LCD
			LCD_WriteString("CORRECT PASS");
			_delay_ms(500);             // delay so user can see sentence
			LCD_Clear();
			num=0;                      // make num with 0 to user can put another num when enter while(1) again if Pass is true
			i=5;                        // i is set by 5 to when enter while(1) again if Pass is true
			TOG=0;	                    // TOG set by 0 so i can break while (1) as  condition is  1  anded with TOG if TOG is 0
		}                               //  while will break
		else if((K=='=')&& (num!=Password))
		{
			LCD_Clear();
			LCD_WriteString("WRONG PASS");
			_delay_ms(500);
			LCD_Clear();
			num=0;           // make num with 0 to user can put another num when enter while(1) again if Pass is true
			i=5;             // i is set by 5 to make user enter pass in same place on LCD
			TOG=1;	         // TOG set by 1 so while contain as it is
		}
}
	}
void High_TEMP_LOW_PRESS()
{
	interrupt_switch_flag_Fan=1;
	LCD_SetCursor(1,6);             // and Temp is more than 500
	LCD_WriteString("HOT");
	LCD_Clear_With_Began(0,0,3);
	LED_ON(2);
	LED_OFF(1);
	LED_OFF(3);
	Stepper_Unipoler_CW_OFF();
	Buzzer_OFF();
	Timer2_OVF_SetCallBack(f9);
	TIMER2_OV_InterruptEnable();
	if(flag_fan==0)
	{
		Fan_OFF();
	}
	else
	{
		Fan_On();
	}
}
void LOW_TEMP()
{
				LCD_SetCursor(1,6);
				LCD_WriteString("FINE");
				LCD_Clear_With_Began(0,0,3);
				LED_ON(1);
				LED_OFF(2);
				LED_OFF(3);
				Stepper_Unipoler_CW_OFF();
				Buzzer_OFF();
				Fan_OFF();

}
void High_PRESS()
{
	LCD_SetCursor(1,6);             // and Temp is more than 500
	LCD_WriteString("HOT");
	LCD_Clear_With_Began(0,0,3);
	LED_ON(2);
	LED_OFF(1);
	LED_OFF(3);
	Stepper_Unipoler_CW_OFF();
	Buzzer_OFF();
}