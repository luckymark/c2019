#include <stdio.h>

 int main()
 {
     int i ;
     for(i = 100;i<=999;i++)
     {
     int a,b,c;
     a = i/100;
     b = i/10 - a*10;
     c = i%10;
     if(i == a*a*a + b*b*b + c*c*c)
     {
         printf("%d\n",i);
     }
     }
     return 0;
 }
