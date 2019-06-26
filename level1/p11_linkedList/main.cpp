#include<stdio.h>
#include<stdlib.h>
#include"function.h"




int main()
{
	PNODE pHead = NULL;//等价于struct List *pHead=NULL
	pHead = create();//函数——创建链表，其中返回值为首结点的地址，这样就便于对链表进行操作
	
	printf("该链表中的数据依次是：\n"); 
	print_all(pHead);//
	
	printf("第一个5的结点位置：\n");
	find_value(pHead,5,1);
	printf("\n第二次出现5的结点位置是：\n");
	find_value(pHead,5,2);	
	
	printf("\n反序结果为：\n"); 
	reverse(pHead);
	print_all(pHead);

	return 0;
}
 

