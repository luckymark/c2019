#include"move.h"
#include<stdlib.h>

extern int yeah;
void maze();
void move();

int main()
{
	printf("这是一个迷宫小游戏^^\n控制方式：WASD，按回车键开始：\n");
	getchar();
	while (1)
	{
		system("cls");
		maze();
		move();
		if (yeah == 1)
		{
			break;
		}
	}
}