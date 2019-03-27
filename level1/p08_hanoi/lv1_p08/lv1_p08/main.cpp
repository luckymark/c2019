#include"move.h"
#include<stdlib.h>


//okkk我写完之后发现写复杂了一点但是我懒得改了……
extern int t;

int main()
{
	int n;
	printf("输入圆盘数量：\n");
	scanf_s("%d", &n);
	AtoC(n);
	printf("移动次数：%d\n", t);
	system("pause");
}