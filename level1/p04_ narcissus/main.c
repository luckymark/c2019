#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,a,b,c;
    for(num=100;num<1000;num++){
        a=num/100;
        b=(num%100)/10;
        c=num%10;
        if(a*a*a+b*b*b+c*c*c==num)
            printf("%5d",num);
    }
    return 0;
}
