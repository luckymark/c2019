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
	printf("����һ��������С��Ϸ^^\n����Ϸ�������ؿ���������1��2��3��ѡ���Ѷȣ�\n");
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