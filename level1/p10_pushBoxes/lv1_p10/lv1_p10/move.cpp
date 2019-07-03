#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"map.h"

int score = 0, yeah = 0;
extern int maparray[11][11],boxnum;
char dir;
struct playerdir
{
	int x;
	int y;
}player;

void move()
{
	dir = _getch();
	if(dir=='w')
	{
		if (maparray[player.x - 1][player.y] == 1 || ((maparray[player.x - 1][player.y] == 2|| maparray[player.x - 1][player.y] == 4) && (maparray[player.x - 2][player.y] == 1 || maparray[player.x - 2][player.y] == 2 || maparray[player.x - 2][player.y] == 4)))//人撞墙或箱子撞墙或箱子撞箱子，地图封闭所以不再考虑越界；
		{	
			return;
		}
		else
		{
			if (maparray[player.x][player.y] == 0)//人的下面是路；
			{
				maparray[player.x][player.y] = -1;
			}
			else if(maparray[player.x][player.y] == 5)//人的下面是目标地点；
			{
				maparray[player.x][player.y] = 3;
			}
			if (maparray[player.x - 1][player.y] == 2 || maparray[player.x - 1][player.y] == 4)//如果行动方向上有箱子或是推到地方的箱子
			{
				if (maparray[player.x - 2][player.y] == 3)//如果刚好推到地方
				{
					maparray[player.x - 2][player.y] = 4;
					if (maparray[player.x - 1][player.y] != 4)//这个箱子本身没有抵达；
					{
						boxnum = boxnum - 1;//一个箱子成功抵达；
					}
					else//这个箱子本身已经抵达；
					{
						maparray[player.x - 1][player.y] = 3;//移动时将记号还原；
					}
				}
				else
				{ 
					maparray[player.x - 2][player.y] = 2;//箱子前移一格；
					if (maparray[player.x - 1][player.y] == 4)
					{
						boxnum = boxnum + 1;//一个箱子被从目标地推出去；
					}
				}
			}
			player.x = player.x - 1;//箱子原先在的位置被人刷掉所以箱子移动那里不变；
		}
	}
	else if (dir == 's')
	{
		if (maparray[player.x + 1][player.y] == 1 || ((maparray[player.x + 1][player.y] == 2|| maparray[player.x + 1][player.y] == 4) && (maparray[player.x + 2][player.y] == 1 || maparray[player.x + 2][player.y] == 2 || maparray[player.x + 2][player.y] == 4)))
		{
			return;
		}
		else
		{
			if (maparray[player.x][player.y] == 0)
			{
				maparray[player.x][player.y] = -1;
			}
			else if (maparray[player.x][player.y] == 5)
			{
				maparray[player.x][player.y] = 3;
			}
			if (maparray[player.x + 1][player.y] == 2 || maparray[player.x + 1][player.y] == 4)
			{
				if(maparray[player.x + 2][player.y] == 3)
				{
					maparray[player.x + 2][player.y] = 4;
					if (maparray[player.x + 1][player.y] != 4)
					{
						boxnum = boxnum - 1;
					}
					else
					{
						maparray[player.x + 1][player.y] = 3;
					}
				}
				else
				{
					maparray[player.x + 2][player.y] = 2;
					if (maparray[player.x + 1][player.y] == 4)
					{
						boxnum = boxnum + 1;
					}
				}
			}
			player.x = player.x + 1;
		}
	}
	else if(dir=='a')
	{
		if (maparray[player.x][player.y - 1] == 1 || ((maparray[player.x][player.y - 1] == 2|| maparray[player.x][player.y - 1] == 4) && (maparray[player.x][player.y - 2] == 1 || maparray[player.x][player.y - 2] == 2 || maparray[player.x][player.y - 2] == 4)))
		{
			return;
		}
		else
		{
			if (maparray[player.x][player.y] == 0)
			{
				maparray[player.x][player.y] = -1;
			}
			else if (maparray[player.x][player.y] == 5)
			{
				maparray[player.x][player.y] = 3;
			}
			if (maparray[player.x][player.y - 1] == 2 || maparray[player.x][player.y - 1] == 4)
			{
				if (maparray[player.x][player.y - 2] == 3)
				{
					maparray[player.x][player.y - 2] = 4;
					if (maparray[player.x][player.y - 1] != 4)
					{
						boxnum = boxnum - 1;
					}
					else
					{
						maparray[player.x][player.y - 1] = 3;
					}
				}
				else
				{
					maparray[player.x][player.y - 2] = 2;
					if (maparray[player.x][player.y - 1] == 4)
					{
						boxnum = boxnum + 1;
					}
				}
			}
			player.y = player.y - 1;
		}
	}
	else if(dir=='d')
	{
	if (maparray[player.x][player.y + 1] == 1 || ((maparray[player.x][player.y + 1] == 2 || maparray[player.x][player.y + 1] == 4) && (maparray[player.x][player.y + 2] == 1 || maparray[player.x][player.y + 2] == 2 || maparray[player.x][player.y + 2] == 4)))
		{
			return;
		}
		else
		{
			if (maparray[player.x][player.y] == 0)
			{
				maparray[player.x][player.y] = -1;
			}
			else if (maparray[player.x][player.y] == 5)
			{
				maparray[player.x][player.y] = 3;
			}
			if (maparray[player.x][player.y + 1] == 2 || maparray[player.x][player.y + 1] == 4)
			{
				if (maparray[player.x][player.y + 2] == 3)
				{
					maparray[player.x][player.y + 2] = 4;
					if (maparray[player.x][player.y + 1] != 4)
					{
						boxnum = boxnum - 1;
					}
					else
					{
						maparray[player.x][player.y + 1] = 3;
					}
				}
				else
				{
					maparray[player.x][player.y + 2] = 2;
					if (maparray[player.x][player.y + 1] == 4)
					{
						boxnum = boxnum + 1;
					}
				}
			}
			player.y = player.y + 1;
		}
	}
	score++;
	if (boxnum == 0)//检测箱子是否全部推到地方
	{
		yeah = 1;
	}
	return;
}