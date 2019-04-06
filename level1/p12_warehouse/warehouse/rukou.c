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
	   printf("菜单：\n1.显示货存列表\n2.入库\n3.出库\n4.退出显示\n");
	   printf("请输入操作：");
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












