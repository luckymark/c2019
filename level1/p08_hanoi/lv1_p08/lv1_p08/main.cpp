#include"move.h"
#include<stdlib.h>


//okkk��д��֮����д������һ�㵫�������ø��ˡ���
extern int t;

int main()
{
	int n;
	printf("����Բ��������\n");
	scanf_s("%d", &n);
	AtoC(n);
	printf("�ƶ�������%d\n", t);
	system("pause");
}