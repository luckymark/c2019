#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"basic.h"
#include"game.h"
#include"map.h"
#pragma warning(disable : 4996)//在VS里fopen没法直接使用，必须关掉警告

int main()
{
	char map[15][15];

	char order[100] = { 0 };
	while (1)
	{
		int score;
		main_menu();
		putchar('\n');
		gets_s(order);
		switch (order[0])
		{
		case '1':loadmap(1, map); score = move(map); record(1, score); break;
		case '2':loadmap(2, map); score = move(map); record(2, score); break;
		case'q':exit(1);
		case'Q':exit(1);
		default:printf("Reinput your order!"); system("pause");
		}
	}
	
}