#include"map.h"
#include"move.h"
#include"record.h"
#include<stdlib.h>

extern int yeah;
void mapcreate();
void move();
void record(int n);

int main()
{
	int lv, create_complete = 0;
	printf("这是一个推箱子小游戏^^\n本游戏共三个关卡，请输入1、2、3来选择难度：\n");
	for (; create_complete == 0;)
	{
		scanf_s("%d", &lv);
		create_complete = mapdesign(lv);
	}
	while (1)
	{
		system("cls");
		mapcreate();
		move();
		if (yeah == 1)
		{
			system("cls");
			printf("Congratulation!!!\n");
			record(lv);
			break;
		}
	}
	system("pause");
}