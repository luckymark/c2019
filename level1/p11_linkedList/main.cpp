#include<stdio.h>
#include<stdlib.h>
#include"function.h"




int main()
{
	PNODE pHead = NULL;//�ȼ���struct List *pHead=NULL
	pHead = create();//�������������������з���ֵΪ�׽��ĵ�ַ�������ͱ��ڶ�������в���
	
	printf("�������е����������ǣ�\n"); 
	print_all(pHead);//
	
	printf("��һ��5�Ľ��λ�ã�\n");
	find_value(pHead,5,1);
	printf("\n�ڶ��γ���5�Ľ��λ���ǣ�\n");
	find_value(pHead,5,2);	
	
	printf("\n������Ϊ��\n"); 
	reverse(pHead);
	print_all(pHead);

	return 0;
}
 

