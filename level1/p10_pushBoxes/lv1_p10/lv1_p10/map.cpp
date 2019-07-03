#include<stdio.h>
#include"move.h"

int maparray[11][11],boxnum;
extern int score;
extern struct playerdir
{
	int x;
	int y;
};
extern playerdir player;

//1为墙，-1为路，0为player，2为箱子，3为目标地点，4为推到地方的箱子，5为人的下面是标记；画地图的时候数字之间用空格隔开；

int mapdesign(int lv)
{
	FILE *fp;
	//errno_t err←用fopen_s需要加一个这个，是用来判断文件是否存在的，有0和1两种值；这里没用，默认地图肯定存在；
	switch (lv)
	{
		case(1):
		{
			fopen_s(&fp, "map1.txt", "r");//注意此处fopen_s和fopen用法不一样；fopen的用法是fp=fopen("map1.txt","r")；
			break;
		}
		case(2):
		{
			fopen_s(&fp, "map2.txt", "r");
			break;
		}
		case(3):
		{
			fopen_s(&fp, "map3.txt", "r");
			break;
		}
		default:
		{
			printf("输入难度有错，请重新输入:(\n");
			return 0;
		}
	}
	for (int line = 0; line < 11; line++)
	{
		for (int row = 0; row < 11; row++)
		{
			fscanf_s(fp, "%d", &maparray[line][row]);
			if (maparray[line][row] == 0)//检测原地图的人物起点位置
			{
				player.x = line;
				player.y = row;
			}
			if (maparray[line][row] == 2)//检测原地图箱子数量
			{
				boxnum++;
			}
		}
	}
	fclose(fp);
	return 1;
}

void mapcreate()
{
	if (maparray[player.x][player.y] == 3 || maparray[player.x][player.y] == 4)//下面是目的地或者推到地方的箱子；
	{
		maparray[player.x][player.y] = 5;
	}
	else//下面是其他的；
	{
		maparray[player.x][player.y] = 0;
	}
	for (int i = 0; i < 11; i++)
	{
		for (int t = 0; t < 11; t++)
		{
			if (maparray[i][t] == 1)
			{
				printf("█");
			}
			else if (maparray[i][t] == -1)
			{
				printf("  ");
			}
			else if (maparray[i][t] == 0 || maparray[i][t] == 5)
			{
				printf("○");
			}
			else if (maparray[i][t] == 2)
			{
				printf("□");
			}
			else if (maparray[i][t] == 3)
			{
				printf("×");
			}
			else if (maparray[i][t] == 4)
			{
				printf("√");
			}
		}
		printf("\n");
	}
	printf("score:%d", score);
	return;
}