#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello \n");
    unsigned char numb1,numb2,anser=0,x,y=0;
    char counter=0;
    char oper;
    char flag=0;
    unsigned char max=0;
    while(1)
    {
    scanf("%d",&numb1);
    for(char i=0;i<8;i++)
    {
       if((numb1>>i)&1)
       {
          flag++;
          if(max<counter)
          {
              max=counter;
          }
          counter=0;
       }
       else
       {
           if(flag>0)
           {
           counter++;
           }
       }
    }
    printf("the number of ones is %d\n",max);
    numb1=0;
    max=0;
    flag=0;
    counter=0;
    /*scanf(" %c",&oper);
    scanf("%d",&numb2);
    if( (numb1>=255 && numb1<=0xFFFFFFFF)  && (numb2>=255 && numb2<=0xFFFFFFFF ) && (oper=='/' || oper=='*' || oper=='+' || oper=='-' || oper=='%' ) )
    {
    if(oper=='*')
    {
        anser=numb1*numb2;
    }
    else if(oper=='/')
    {
        anser=numb1/numb2;
    }
    else if(oper=='%')
    {
        anser=numb1%numb2;
    }
    else if(oper=='+')
    {
        anser=numb1+numb2;
    }
    else if(oper=='-')
    {
        anser=numb1-numb2;
    }
    printf("=%d",anser);
    printf("\n");
    }
    else
    {
        printf("Wrong Operation\n");
    }*/

    }
    return 0;
}
