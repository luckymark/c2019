#include <stdio.h>
 int main()
{
   unsigned int  a;
   printf("��������һ��������:");
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
      printf("%u��������\n",a);
   }
   else
   {
      printf("%u����������\n",a);
   }
 
   return 0;
}

