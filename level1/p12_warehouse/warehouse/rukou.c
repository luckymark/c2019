#include<stdio.h>
#include<string.h>
#include"warehouse.h"
int main()
{
    int n;
	cnt=0;
	duru();
	xianshi();
    while(1)
    {
	   printf("�˵���\n1.��ʾ�����б�\n2.���\n3.����\n4.�˳���ʾ\n");
	   printf("�����������");
	   scanf("%d",&n);
	   switch(n)
	   {
		   case 1:
			   xianshi();
			   break;
		   case 2:
			   ruku();
			   break;
		   case 3:
			   chuku();
			   break;
		   case 4:
			   tuichu();
			   break;
		   default:
			   break;
	   }
	   if(n==4){
           break;
	   }
	   if(n>4){
		   printf("\n\n");
		   continue;
	   }
    }
    return 0;
}












