#include"move.h"
#include<stdlib.h>

extern int yeah;
void maze();
void move();

int main()
{
	printf("����һ���Թ�С��Ϸ^^\n���Ʒ�ʽ��WASD�����س�����ʼ��\n");
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