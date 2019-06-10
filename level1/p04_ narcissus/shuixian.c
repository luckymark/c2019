#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a,b,c,i,num;

    for(i=100;i<1000;i++)
    {
        num = i;
        a=num%10;
        num /= 10;
        b=num%10;
        num /= 10;
        c = num;
        if(i == (pow(a,3)+pow(b,3)+pow(c,3)))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
