#include "StdTypes.h"
#include "Math_Service.h"
u8 Math_Is_number_baseof2_1(u16  n)
{
    while(n!=1&&n>0)
    {
        n=n/2;
    }
    if(n==1)
    {
       return 1;

    }
    else
    {
        return 0;

    }
}
/****************************************************************************************************/
u8 Math_Is_number_baseof2_2(u16  n)
{
    u16 x,y;
    x=n-1;
    y=x&n;
    if(y==0)
    {
         return 1;

    }
    else
    {
         return 0;
    }

}
/****************************************************************************************************/
u8 Math_Is_number_baseof2_3(u16  n)
{
    u16 x,y;
    x=~n;
    ++x;
    y=x&n;
    if(y==n)
    {
         return 1;

    }
    else
    {
         return 0;

    }

}
/****************************************************************************************************/	
void Math_max_min_for_TWO_numbers_return_Two_pou16ers(u16 x,u16 y ,u16 *m,u16 *n )
{
    if(y>x)
    {
        *m=y;
        *n=x;
    }
    if(y<x)
    {
        *m=x;
        *n=y;
    }
}
/****************************************************************************************************/
u16 Math_Mul_by_addation (u16 x,u16 y)
{
    u16 Mul=0;
   for(u16 i=0;i<x;i=i+1)
   {
    Mul=Mul+y;
   }
   return Mul;
}
/****************************************************************************************************/
u16 Math_remd_by_Mul_DivD(u16 x,u16 y)
{
    u16 remd=0,z;
    z=x/y;
    remd=x-(z*y);
    return remd;
}
/****************************************************************************************************/
u16 Math_power_By_Mul(u16 x,u16 y)
{
    u16 z=1;
   for( u16 i=0; i<y;i=i+1)
    {
        z=z*x;
    }
    return z;
}
/****************************************************************************************************/
u16 Math_factorial (u16 x)
{
    u16 y,z=1;
   y=x;
    for( u16 i=0; i<y;i=i+1)
    {
        z=z*x;
        x--;
    }
    return z;
}
/****************************************************************************************************/
u8 Math_Is_Number_prime (u16 x)
{
    u16 y,z=0;
    for(u16 i=2;i<=x/2 && z==0;i=i+1)
      {
          if(x%i==0)
          {
              z=1;
          }
      }
        if(z==0)
        {
           return 1;
        }
        else
        {
          return 0;
        }
}
/****************************************************************************************************/
u16 Math_Is_Number_prefectsquare (u16 x)
{
    u16 y,z=0;
    for(u16 i=1;i<=x && z==0;i=i+1)
      {
          if(i*i==x)
          {
              z=1;

          }

      }
        if(z==1)
        {
          return 1;
        }
        else
        {
          return 0;
        }

}
/****************************************************************************************************/
u8 Math_sum_of_digits_of_Number (u16 x)
{
    u16 sum=0,z=0,remd=0;
       while(x>0)
        {

            remd=x%10;
            sum=sum+remd;
            x=x/10;
        }
        return sum;
}
/****************************************************************************************************/
u16 Math_revese_number (u16 x)
{
    u16 sum=0,y=0,c=0;
       for(u16 i=0; 0<x; ++i)
        {
            y=x%10;
            x=x/10;
            c=y+c*10;
        }
        return c;
}
/****************************************************************************************************/
u16 Math_Is_Number_power_of_3(u16 x)
{
    u16 min=0x800000,max=0xFFFFFFFF;
    for(;x>1;)
    {
        x=x/3;

    }
    if (x==1)
    {
        return 1;   
	}
    else
    {
      return 0;    
	}
}
/****************************************************************************************************/
/*void maxminforgivennumbers(u16 x,int y ,int *m,int *n )
{
    int max=0x80000000;
    int min=0x7FFFFFFF;
    for(int i=0;i<x;i=i+1)
    {
       printf("Please enter  numbers %d\n",y);

    if(y>max)
    {
        max=y;
    }

       printf("Please enter  numbers %d\n",max);


    if(y<min)
    {
        min=y;
    }


    }
    *m=max;
    *n=min;
}
void area_and_circ_by_Pointers(u16 r,u16 n, float*c, float*a)
{
	float r,pi=3.14 ;
	printf("\n please enter Radius\n");
	scanf("%f",&r);

	*a=pi*r*r;

	*c=2*pi*r;
}
int sum(void)
{
	int sum=0;
	sum=55+(100*1+55)+(100*2+55)+(100*3+55)+(100*4+55)+(100*5+55)+(100*6+55)+(100*7+55)+(100*8+55)+(100*9+55);
	return sum;
}
*/


