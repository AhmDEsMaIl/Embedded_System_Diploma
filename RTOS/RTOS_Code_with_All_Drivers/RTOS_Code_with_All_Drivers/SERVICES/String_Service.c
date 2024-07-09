/*
 * String_Service.c
 *
 * Created: 10/10/2023 6:44:36 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "String_Service.h"
/****************************************************************************************************/
u16 String_length(u8 *str)
{
	u16 i=0;
	for(i=0;str[i];i++)
	{

	}
	//printf("\n");
	return i;
}
/****************************************************************************************************/
void String_revse (char *str)
{
	u16 l = string_length(str);
	char temp=0;
	for(u16 i=0;i<l/2;i++)
	{
		temp=str[i];
		str[i]=str[l-1];
		str[l-1]=temp;
	}
}
/****************************************************************************************************/
u16 String_Convert_String_INT(char *str)
{
	u16 i=0,remd=0,flag=0;
	if(str[i]='-')
	{
		flag=1;
		i++;
	}
	for(;str[i];i++)
	{
		remd=remd*10+(str[i]-'0');
	}
	if(flag==1)
	{
		remd*=(-1);
	}
	return remd;
}
/****************************************************************************************************/
char String_IS_String_Is_mirror (u8 *str)
{
	char str1[100];
	u16 i;
	for(i=0;str[i];i++)
	{
		str1[i]=str[i];
	}
	str1[i]=0;
	reverse_string(str1);
	for(i=0;str[i];i++)
	{
		if(str1[i]!=str[i])
		{
			return 0;
		}
	}
	return 1;
}
/****************************************************************************************************/
void String_Convert_INT_string(u8 *str,u16 n)
{
	u16 i=0,remd=0,flag=0;
	if(n<0)
	{
		n=n*(-1);
		flag=1;
	}
	while(n)
	{
		remd=n%10;
		str[i]=remd+'0';
		i++;
		n=n/10;
	}
	if(flag==1)
	{
		str[i]='-';
		i++;
	}
	str[i]=0;
	String_revse(str);
}
/****************************************************************************************************/
void String_Convert_Float_string (double num, u8 * str)
{
	u16 i,remd;
	float temp=num-(u16)num;

	while(temp!=(u16)temp)
	{
		temp=temp*10;
	}
	u16 n=temp;
	while(n)
	{
		remd=n%10;
		str[i]=remd+'0';
		i++;
		n=n/10;
	}
	str[i]='.';
	i++;
	n=num;
	while(n)
	{
		remd=n%10;
		str[i]=remd+'0';
		i++;
		n=n/10;
	}
	str[i]=0;
	String_revse(str);
}
/****************************************************************************************************/
/*void inttostring (int n,char str[])
{
    int i=0,rem=0;
    if(n==0)
    {
        str[0]='0';
        str[1]=0;
    }
    else if ( n<0)
    {
       n=n*(-1);
       i=1;
       while(n)
    {
        rem=n%10;
        rem=rem+'0';
        str[i]=rem;
        i++;
        n=n/10;
    }
     String_revse(str);
     str[0]='-';

    }
    else
    {
        i=0;
    while(n)
    {
        rem=n%10;
        rem=rem+'0';
        str[i]=rem;
        i++;
        n=n/10;
    }
    String_revse(str);
    }

    str[i]=0;
}
int stringtoint (char str[],int *p1)
{
    int x=0,c=0,i=0,flag=0;
    if(str[0]=='-')
    {
        flag=1;
        i++;
    }
    for(;str[i];i++)
    {
        if(str[i]>='0' && str[i]<='9')
       {
        x=str[i]-'0';
        c=c*10+x;
        }
        else
        {
            return 0;
        }
    }
    if(flag==1)
    {
        c=c*-1;
    }
    *p1=c;
    return 1;
}
*/
/*
void String_printf(int str[])
{
	for(int i=0;str[i];i++)
	{
		printf("%c",str[i]);
	}
	printf('\n');
}
void String_Scan(u8 str[])
{
	u16 i=0;
	scanf(" %c",&str[i]);
	for(;str[i]!='\n';)
	{
		i++;
		scanf("%c",&str[i]);
	}
	str[i]=0;
}
*/