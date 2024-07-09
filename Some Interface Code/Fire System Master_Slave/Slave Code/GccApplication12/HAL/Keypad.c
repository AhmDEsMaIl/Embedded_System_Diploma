/*
 * Keypad.c
 *
 * Created: 11/30/2022 12:28:50 AM
 *  Author: ahmed
 */ 
/*
 * KeyPad.c
 *
 * Created: 3/14/2021 1:46:54 PM
 *  Author: khaliid
 */ 

#include "Keypad.h"
#include "Math.h"
/******************************************************************************/
static u8 KeysArray[ROWS][COLS]={{'7','8','9','/'},
						        {'4','5','6','*'},
							    {'1','2','3','-'},
						    	{'c','0','=','+'}};
/*****************************************************************************/
void KEYPAD_Init(void)
{
	DIO_WritePin(FIRST_OUT,HIGH);
	DIO_WritePin(FIRST_OUT+1,HIGH);
	DIO_WritePin(FIRST_OUT+2,HIGH);
	DIO_WritePin(FIRST_OUT+3,HIGH);
}

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	
	
	for(r=0;r<ROWS;r++)
	{
		DIO_WritePin(FIRST_OUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			if(DIO_ReadPin(FIRST_IN+c)==LOW)
			{
				key=KeysArray[r][c];
				while(DIO_ReadPin(FIRST_IN+c)==LOW);
			}
		 }
		DIO_WritePin(FIRST_OUT+r,HIGH);
	}
	return key;
}
u32 KEYPAD_DEC(u8 k)
{
	u32 num=0;
	if(k!=NO_KEY)
	{
	 if(k>='0' && k<='9')
	 {
		 num=num*10+(k-'0');
	 }
	 return num;
	}
}
void KEYPAD_BIN_Display(u8 *arr,u8 k,u8 size)
{
	static s8 i=0;
	
	if(k=='0')
	{
		arr[i]=0;
		i++;
	}
	if(k=='1')
	{
		arr[i]=1;
		i++;
	}
	if(k=='c'|| i==size+1)
	{
		
		 while(i>=0)
		 {
             arr[i]=0;
			 i--;
		 }
		 i=0;
	}
}

u16 KEYPAD_BIN_T_DEC_CONV(u8 *arr,u8 size)
{
	u16 sum=0;
	u8 i=0,pres=0,prev=0;
    for(i=0;i<size;i++)
	{
		if(i==0)
		{
			pres=1;
			prev=1;
		}
		else
		{
			prev=2;
		}
		
		if(arr[i])
		{
			pres=pres*prev;
			sum=sum+pres;
		}
	}
	return sum;
}
void KEYPAD_HEX_Display(u8 *arr,u8 k,u8 size)
{
	 static  s8 i=0;
	 if(k>='0' && k<='9')
	 {
		arr[i]=k;
		 i++;
	 }
	 else if(k=='/')
	 {
		 arr[i]='A';
		  i++;
	 }
	 else if(k=='*')
	 {
		arr[i]='B';
		 i++;
	 }
	 else if(k=='-')
	 {
		 arr[i]='C';
		  i++;
	 }
	 else if(k=='+')
	 {
		 arr[i]='D';
		  i++;
	 }
	 else if(k=='=')
	 {
		 arr[i]='E';
		  i++;
	 }
	 else if(k=='c')
	 {
		 arr[i]='F';
		  i++;
	 }
	 if(i==(size+1))
	 {
		 while(i>=0)
		 {
			 arr[i]=0;
			 i--;
		 }
		 //i=0;
	 }
	
}
u32 KEYPAD_HEX_T_DEC_CONV(u8 *arr,u8 k,u8 size)
{
	u32 num=0;          //incomplete there is an bug , function return num variable  with 0 not equivalent of  num of hex  return num
	u8 i=0;
	for(i=0;i<size;i++)
	{
	if(arr[i]>='0' && arr[i]<='9')
	{
		num=num+arr[i]-'0';
		
	}
	 if(arr[i]=='A')
	{
		num=num+10;
		
	}
	 if(arr[i]=='B')
	{
		num=num+11;
		
	}
	 if(arr[i]=='C')
	{
		num=num+12;
		
	}
    if(arr[i]=='D')
	{
		num=num+13;
		
	}
    if(arr[i]=='E')
	{
		num=num+14;
		
	}
    if(arr[i]=='F')
	{
		num=num+15;
		
	}
	}
	return num;
}