#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"maze.h"

int yeah = 0;
extern int mazearray[21][21];
char dir;
struct playerdir
{
	int x=0;
	int y=10;
}player;

void move()
{
	dir = _getch();
	if(dir=='w')
	{
		if (player.x - 1 < 0 || mazearray[player.x - 1][player.y] == 1)//×²Ç½»òÔ½½ç
		{	
			return;
		}
		else
		{
			mazearray[player.x][player.y] = -1;
			player.x = player.x - 1;
		}
	}
	else if (dir == 's')
	{
		if (mazearray[player.x + 1][player.y] == 1)
		{
			return;
		}
		else
		{
			mazearray[player.x][player.y] = -1;
			player.x = player.x + 1;
		}
	}
	else if(dir=='a')
	{
		if (mazearray[player.x][player.y - 1] == 1)
		{
			return;
		}
		else
		{
			mazearray[player.x][player.y] = -1;
			player.y = player.y - 1;
		}
	}
	else if(dir=='d')
	{
		if (mazearray[player.x][player.y + 1] == 1)
		{
			return;
		}
		else
		{
			mazearray[player.x][player.y] = -1;
			player.y = player.y + 1;
		}
	}
	if (player.x == 10 && player.y == 10)
	{
		system("cls");
		printf("Congratulation!!!\n");
		yeah = 1;
		system("pause");
	}
	return;
}