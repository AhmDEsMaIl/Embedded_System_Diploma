#include "StdTypes.h"
#include "Array_Service.h"
void Array_countSort_mono(u16*arr,u16 size)
{
    u16 i,j,count[10]= {0};
    for(i=0; i<size; i++)
    {
        count[arr[i]]++;
    }

    j=0;
    for(i=0; i<10; i++)
    {
        while(count[i])
        {
            arr[j]=i;
            count[i]--;
            j++;
        }
    }

}
/***************************************************************************************************/
void Array_selectionSort_1(u16*arr,u16 size)
{
    u16 max_i,i,j,last=size-1,max,temp;
    for(j=0; j<size; j++)
    {
        // max=arr[0];
        max_i=0;
        for(i=0; i<=last; i++)
        {
            if(arr[i]>arr[max_i])
            {
                max_i=i;
                //max=arr[i];
            }
        }
        temp=arr[last];
        arr[last]=arr[max_i];
        arr[max_i]=temp;
        last--;
    }

}

/***************************************************************************************************/
void Array_swap_Two_element (u16* px, u16* py)
{
    u16 temp;
    temp=*px;
    *px=*py;
    *py=temp;
}
/***************************************************************************************************/
u16 Array_findmax(u16*arr,u16 size)
{

    u16 i,max_i=0;
    for(i=0; i<size; i++)
    {
        if(arr[i]>arr[max_i])
        {
            max_i=i;
        }
    }
    return max_i;
}
/***************************************************************************************************/
u16  Array_max_min(u16 *arr,u16 s,u16*x, u16*y)
{
	u16 min=0x8000000,max=0xFFFFFFFF;
	for(u16 i=0;i<s;++i)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(min>arr[i]) //////when i use elseif the loweset numb is 2 not 1
		{
			min=arr[i];
		}

	}
	*x=max;
	*y=min;
}
/***************************************************************************************************/
void Array_selectionSort_2(u16*arr,u16 size)
{
    u16 max_i,i,j,last=size-1,max,temp;
    for(j=0; j<size; j++)
    {
        max_i=Array_findmax(arr,last+1);
        Array_swap_Two_element (&arr[max_i],&arr[last]);
        last--;
    }

}
/***************************************************************************************************/
void Array_BubbleSort(u16*arr,u16 size)
{
    u16 j,i,temp,c=0,sorted_flag=0;

    for(j=0; j<size; j++)
    {
        sorted_flag=1;
        for(i=0; i<size-1-j; i++)
        {
            c++;
            if(arr[i]<arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                sorted_flag=0;
            }
        }
        if(sorted_flag==1)
        {
            break;
        }
    }
    //pru16f("size=%d   c=%d\n",size,c);

}
/***************************************************************************************************/
u16 Array_mostRepeated_Frequency_array(u16*arr,u16 size,u16*pnum)
{
    u16 i,max=0,count_size,max_num=arr[0],min_num=arr[0];
    for(i=0; i<size; i++)
    {
        if(arr[i]>max_num)
        {
            max_num=arr[i];
        }
        if(arr[i]<min_num)
        {
            min_num=arr[i];
        }
    }
    count_size=max_num-min_num+1;
    u16*count=(u16*)calloc(count_size,sizeof(u16));

    for(i=0; i<size; i++)
    {
        count[arr[i]-min_num]++;
    }
    /*for(i=0; i<count_size; i++)
    {
        printf("%d    %d   %d\n",i,i+min_num,count[i]);
    }*/
    for(i=0; i<count_size; i++)
    {
        if(max<count[i])
        {
            max=count[i];
            *pnum=i+min_num;
        }
    }
    free(count);
    return max;
}
/****************************************************************************************************/
u16 Array_repeated_number(u16 *arr,u16 s)
{
	u16 min=0x800000,max=-1;
	u16 i,j,c=0,y,x;
	for(i=0; i<s; i++)
	{
		for(j=i+1; j<s; j++)
		{
			if(arr[i]==arr[j])
			{

				c++;

			}
		}
		if(c>max)
		{
			max=c;
			x=i;
		}
	}
	if( c==0)
	{
		return -1;
	}
	else
	{
		return arr[x];
	}
}
/****************************************************************************************************/
u16 Array_count_given_number_in_array(u16 *ar,u16 s,u16 numb)
{
	u16 max=0,x=0,c=0;
	for(u16 i=0;i<s;i++)
	{
		if(ar[i]==numb)
		{
			c++;
		}

	}
	if(c>=1)
	{
		return c;
	}

	return -1;
}
/****************************************************************************************************/
u16 Array_mostRepeated_sorted(u16 *arr,u16 size,u16 *pnum)
{
	u16 i,j,c=0,max=0,c2=0;
	for(i=0; i<size-1; i++)
	{
		if(arr[i]==arr[i+1])
		{
			c++;
		}
		else
		{
			c=0;
		}
		if(c>max)
		{
			max=c;
			*pnum=arr[i];
		}

	}
	return max+1;
}
/****************************************************************************************************/
u16 array_binarySearch(u16*arr,u16 size,u16 num)
{
	u16 f,l,m,c=0;
	f=0;
	l=size-1;
	while(1)
	{
		c++;
		//printf("c=%d\n",c);
		m=(f+l)/2;
		if(arr[m]==num)
		{
			return m;
		}
		else if(arr[m]>num)
		{
			l=m-1;
		}
		else
		{
			f=m+1;
		}
		if(f>l)
		{
			break;
		}
	}
	return -1;

}
/****************************************************************************************************/
void Array_revse(u16 *arr,u16 s)
{

	u16 i,c=0,j=s-1;
	for( i=0;i<s/2;i++)
	{

		c=arr[j];
		arr[j]=arr[i];
		arr[i]=c;

		j--;
	}
}
/****************************************************************************************************/
void  Array_Two_array_swap_With_Small_Size (u16 *arr,u16 *ar,u16 s1, u16 s2)
{

	u16 i,c=0,j=0,S;
	if(s1>s2)
	{
		S=s2;
	}
	else
	{
		S=s1;
	}
	for( i=0;i<S;i++,j++)
	{
		c=arr[i];
		arr[i]=ar[j];
		ar[j]=c;
	}
}
/****************************************************************************************************/
u16 Array_longest_consecutive_in_given_array (u16 *arr ,u16 s,u16*p1)
{
	u16 k,c=0,max=0;
	for(u16 i=0;i<s-1; i++)
	{
		if(arr[i]==arr[i+1])
		{
			c++;
			if(c>max)
			{
				max=c;
				*p1=i;
			}
		}
		else
		{
			c=0;
		}
		//printf("c= %d    arr[i]%d      arr[i+1]%d    *p1   %d    i%d\n",c,arr[i],arr[i+1],*p1,i);
	}
	return max+1;
}
/****************************************************************************************************/
u16 Array_merging_Two_Array_With_Big_Array (u16 *arr,u16 s1,u16 *ar,u16 s2, u16 *a,u16 s3)
{
	u16 j=0,k=0;

	for(u16 i=0;i<s3;)
	{
		if(k<s2 )
		{

			a[i]=arr[j];
			i++;
			a[i]=ar[k];
			i++;
			j++;
			k++;
		}
		else
		{
			a[i]=arr[j];
			j++;
			i++;
		}
	}
}
/****************************************************************************************************/
/*int print_numbers_between_array(int *arr,int s,int x, int y)
{

    x++;
    y--;
    for(int i=0;i<s;i++, x++)
    {

      if (y<x)
      {
          break;
      }
      else
      {
          arr[i]=x;
      }


    }
    return arr;
}*/


/*int seaeching_with_number_of_longest_consecutive (int arr[] ,int s,int*p1,int numb)
{
    int k,c=0,max=0;
    for(int i=0;i<(s-1);)
    {
          if(numb==arr[i+1])
          {
              c++;
              if(c>max)
              {
                  max=c;
                  *p1=i;
              }
          }
          else
          {
              c=0;
          }
           //printf("c= %d    numb%d      arr[i+1]%d    *p1   %d    i%d\n",c,numb,arr[i+1],*p1,i);
            i++;


    }
    return max;
}*/
