/*
 * URAT_Services.c
 *
 * Created: 2/28/2023 7:32:21 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "URAT_Services.h"
#include "LCD.h"
void URAT_SendString(u8 *str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		URAT_Send_Data(str[i]);
	}
	URAT_Send_Data('#');
}

void URAT_ReceiveString(u8 *str)
{
	u8 i=0;
	str[i]=URAT_Recieve_Data();
	for(;str[i]!=13&&str[i]!=10  ;)
	{
		i++;
		str[i]=URAT_Recieve_Data();
	}
	str[i]=0;
}
void URAT_SendNumber(u32 numb)
{
	URAT_Send_Data((u8)numb);
	URAT_Send_Data((u8)(numb>>8));
	URAT_Send_Data((u8)(numb>>16));
	URAT_Send_Data((u8)(numb>>24));
	
	/*u8 *p=&numb;
	URAT_Send_Data(p[0]);
	URAT_Send_Data(p[1]);
	URAT_Send_Data(p[2]);
	URAT_Send_Data([p[3]);*/
}
u32 URAT_ReceiveNumber()
{
	u8 b1=URAT_Recieve_Data();
	u8 b2=URAT_Recieve_Data();
	u8 b3=URAT_Recieve_Data();
	u8 b4=URAT_Recieve_Data();
    u32 num=(u32)b1| (u32)b2<<8 |(u32)b3<<16 | (u32) b4<<24;
	
	/*u8 *p=&num;
	p[0]=URAT_Recieve_Data();
	p[1]=URAT_Recieve_Data();
	p[2]=URAT_Recieve_Data();
	p[3]=URAT_Recieve_Data();*/
}
Endian Check_Endian(void)
{
	u32 num=1;
	u8 *p=&num;
	if(*p==1)
	{
		return LITTLE;
	}
	else
	{
		return BIG;
	}
}

u32 Endian_Convert_u32(u32 num)
{
	return (num>>24) | (num<<24) | (num<<8)& (0x00ff0000) | (num>>8) &(0x0000ff00);
	/*u8 *p=&num;
	u8 temp;
	temp=p[0];
	p[0]=p[3];
	p[3]=temp;
	
	temp=p[2];
	p[2]=p[1];
	p[1]=temp;
	return num */
}
void URAT_SendStringchecksum(u8 *str)
{
	u8 l=0;
	u16 sum=0;
	for(l=0;str[l];l++);
	URAT_Send_Data(l);
	for(l=0;str[l];l++)
	{
		URAT_Send_Data(str[l]);
		sum+=str[l];
	}
	URAT_Send_Data((u8)sum);
	URAT_Send_Data((u8)(sum>>8));

}
u8 URAT_ReceiveStringchecksum(u8 *str)
{
	u8 i,b1,b2,l=URAT_Recieve_Data();
	u16 sum,check;
	for(i=0;i<l;i++)
	{
		str[i]=URAT_Recieve_Data();
		sum+=str[i];
	}
	str[i]=0;
	b1=URAT_Recieve_Data();
	b2=URAT_Recieve_Data();
	check=(u16)b1 | (u16)(b2<<8);
	if(check==sum)
	{
		return 1;
	}
	return 0;
}
u8 volatile *TX_str[3]={0},k=0;
u8 volatile j=0;
u8 volatile f=0;
void TX_Fun()
{
	u8 static i=1,c=0;
	if(TX_str[j][i]!=0)
	{
		URAT_sendNoBlock(TX_str[j][i]);
		i++;
		c=0;
	}
	else
	{
		TX_str[j]=0;
		i=0;
		
		if(c==0)
		{
			c='#';
			URAT_sendNoBlock('#');
			j++;
			//f=0;
		}
		
		if(j==3)
		{
			j=0;
			LCD_SetCursor(1,6);
			LCD_WriteNumber(TX_str[0]);
			while(1);
		}	
		
	}
}
void URAT_SendStringAshync(u8* str)
{
	u8 static f2=1,c1=4,c2=0,c3=0;
	if(f==0)
	{
		UART_TX_SetCallBack(TX_Fun);
		TX_str[j]=str;
		URAT_sendNoBlock(TX_str[j][0]);
		UART_TX_InterruptEnable();
		f=1;
	}
	else
	{
				
		if(f2==0)
		{
			TX_str[0]=0;
             LCD_SetCursor(1,10);
             LCD_WriteNumber(TX_str[0]);
			f2=1;
			
		}
		else if(f2==1)
		{
			TX_str[1]=str;
			
			f2=2;
		}
		else if(f2==2)
		{
			TX_str[2]=str;
			f2=0;
		
		}

		
	}
}


u8 stack[STACK_SIZE];
u8 sp=0;

u8  push(u8 data)
{
	if(sp==STACK_SIZE)
	{
		return STACK_FULL;
	}
	else
	{
		stack[sp]=data;
// 		LCD_SetCursor(1,0);
// 		LCD_WriteChar(stack[sp]);

		sp++;
		return STACK_DONE;
	}

}

u8  pop(u8 *pdata)
{
	
	if(sp==0)
	{
		return STACK_EMPTY;
	}
	else
	{
		sp--;
		LCD_SetCursor(1,0);
		LCD_WriteString("fff");
         //LCD_WriteChar('j'); 
		*pdata=stack[sp];
		return STACK_DONE;
	}

}
void Stack_In()
{
	 UART_RX_SetCallBack(Stack_INT);
	 UART_RX_InterruptEnable();
}
void Stack_INT()
{
	URAT_Stack_push();
}
void URAT_Stack_push()
{
	u8 x=URAT_ReceiveNoBlock();
	
	u8 y=push(x);
	if(y==STACK_FULL)
	{
		LCD_WriteString("stack full");
	}
	
}
u8 URAT_Stack_pop()
{
	u8 y;
	u8 x=pop(y);
	LCD_WriteChar(y);
	if(x==STACK_EMPTY)
	{
		LCD_WriteString("stack empty");
	}
	return y;
}