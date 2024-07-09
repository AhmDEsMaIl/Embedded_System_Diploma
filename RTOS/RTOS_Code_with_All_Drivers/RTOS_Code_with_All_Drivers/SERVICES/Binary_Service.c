/*
 * Binary_Service.c
 *
 * Created: 10/10/2023 8:25:12 PM
 *  Author: ahmed
 */ 
#include "StdTypes.h"
#include "Binary_Service.h"
int Binary_swap_Two_Bits_in_a_Number(u16 n,u16 bit1,u16 bit2)
{
	n=n^(1<<bit1);
	n=n^(1<<bit2);
	return n;
}
/****************************************************************************************************/
u16 Binary_number_of_ones_in_Number(u16 x)
{
	u16 c;
	for(u16 i=0; i<32; ++i)
	{
		if((x>>i)&1)
		{
			++c;
		}
	}
	return c;
}
/****************************************************************************************************/
u16 Binary_max_Number_zeros_consecutive(u16 n)
{
	u16 i,c1=0,one=1;
	for(i=1;i<=32;i++)
	{
		++c1;
		if((n&one)==one)
		{
			one=one<<1;
			break;
		}
		one=one<<1;
	}
	u16 max=0,c2=c1;
	for (u16 j=i+1;j<=32;j++)
	{
		++c2;
		if((n&one)==one)
		{
			if(max<c2-c1-1)
			{
				max=c2-c1-1;
			}
			c1=c2;
		}
		one=one<<1;
	}
	return max;
}
/****************************************************************************************************/
/*int c1clear2set3toggle4readbits (int x,int y,int z)
{
    int c;

    switch(z)
    {
    case 1:
        c=(~(1<<y))&x;
        printf("\n The clear %d",c);
        break;

    case 2:
        c=(1<<y)|x;
        printf("\n The Set  is%d",c);
        break;

    case 3:
        c=(1<<y)^x;
        printf("\n The toggle is %d",c);
        break;

    case 4:
        c=(x>>y)&1;
        printf("\n The Read is %d",c);
        break;
    }
}
int xor(int n, int m)
{
    int y=0,max=0xFFFFFFFF;
    if(n>m)
    {
        for(int i=m;i<=n;i++)
        {
            for(int j=m;j<=n;j++)
            {
                y=i^j;
                if(y>max)
                {
                    max=y;
                }
            }
        }
    }
    else
    {
        for(int i=n;i<=m;i++)
        {
            for(int j=n;j<=m;j++)
            {
                y=i^j;
                if(y>max)
                {
                    max=y;
                }
            }
        }

    }
    return max;
}
int showinbinary(int x)
{
	int count=0,y;
	for(int i=0;i<32;i++)
	{

		if((x>>i)&1)
		{
			++count;
		}
	}

	for(int i=0;count>0;i++)
	{

		y=(x>>i)&1;
		printf("  %d",y);

		if( x>>i&1  )
		{

			--count;

		}
	}
}
}
*/