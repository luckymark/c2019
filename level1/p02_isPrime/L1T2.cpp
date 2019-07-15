#include <stdio.h>
 int main()
{
   unsigned int  a;
   printf("请您输入一个正整数:");
   scanf("%u",&a);
   int  i,b=0;
      for(i=1;i<=a;i++)
   {
      if(a%i==0)
      {
         b++;
      }
   }
   if(b==2||b==1)
   {
      printf("%u是素数。\n",a);
   }
   else
   {
      printf("%u不是素数。\n",a);
   }
 
   return 0;
}

