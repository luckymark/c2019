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
		if (maparray[player.x - 1][player.y] == 1 || ((maparray[player.x - 1][player.y] == 2|| maparray[player.x - 1][player.y] == 4) && (maparray[player.x - 2][player.y] == 1 || maparray[player.x - 2][player.y] == 2 || maparray[player.x - 2][player.y] == 4)))//��ײǽ������ײǽ������ײ���ӣ���ͼ������Բ��ٿ���Խ�磻
		{	
			return;
		}
		else
		{
			if (maparray[player.x][player.y] == 0)//�˵�������·��
			{
				maparray[player.x][player.y] = -1;
			}
			else if(maparray[player.x][player.y] == 5)//�˵�������Ŀ��ص㣻
			{
				maparray[player.x][player.y] = 3;
			}
			if (maparray[player.x - 1][player.y] == 2 || maparray[player.x - 1][player.y] == 4)//����ж������������ӻ����Ƶ��ط�������
			{
				if (maparray[player.x - 2][player.y] == 3)//����պ��Ƶ��ط�
				{
					maparray[player.x - 2][player.y] = 4;
					if (maparray[player.x - 1][player.y] != 4)//������ӱ���û�еִ
					{
						boxnum = boxnum - 1;//һ�����ӳɹ��ִ
					}
					else//������ӱ����Ѿ��ִ
					{
						maparray[player.x - 1][player.y] = 3;//�ƶ�ʱ���ǺŻ�ԭ��
					}
				}
				else
				{ 
					maparray[player.x - 2][player.y] = 2;//����ǰ��һ��
					if (maparray[player.x - 1][player.y] == 4)
					{
						boxnum = boxnum + 1;//һ�����ӱ���Ŀ����Ƴ�ȥ��
					}
				}
			}
			player.x = player.x - 1;//����ԭ���ڵ�λ�ñ���ˢ�����������ƶ����ﲻ�䣻
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
	if (boxnum == 0)//��������Ƿ�ȫ���Ƶ��ط�
	{
		yeah = 1;
	}
	return;
}