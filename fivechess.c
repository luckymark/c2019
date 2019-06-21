#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define H 26           
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define ok 'j'	
int x, y, nextx, nexty, wint, turn, now, you, maxm = 0, maxy = 0, maxmcoordx = 0, maxmcoordy = 0, maxycoordx = 0, maxycoordy = 0, map[H][H];
void init_map_array() 
{
	system("cls");
	int i, j;
	for (i = 0; i < H; i++)
		for (j = 0; j < H; j++)
			map[i][j] = 9;
	x = H / 2, y = H / 2;
	for (i = 4; i < H - 4; i++)
		for (j = 4; j < H - 4; j++)
			map[i][j] = 4;
	map[x][y] = 3;
}
void drawMap() 
{
	int i, j;
	for (i = 4; i < H - 4; i++)
	{
		for (j = 4; j < H - 4; j++)
		{
			if (map[i][j] == 4)
			{
				if (i==4&&j==4) printf("\t��");
				else if (i == 4 && j == H - 5) printf("��");
				else if (i == H - 5 && j == 4) printf("\t��");
				else if (i == H - 5 && j == H - 5) printf("��");
				else
				{
					switch (j)
					{
					case H - 5:printf("��"); break;
					case 4:printf("\t��"); break;
					default:
						switch (i)
						{
						case 4:printf("��"); break;
						case H - 5:printf("��"); break;
						default:printf("��"); break;
						}
						break;
					}
				}
			}
			if (map[i][j] == 1)
				printf("��");
			if (map[i][j] == 0)
				printf("��");
			if (map[i][j] == 3)
				printf("��");
		}
		printf("\n");
	}
	printf("�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
}
void swap()
{
	int temp;
	temp = map[nextx][nexty];
	map[nextx][nexty] = map[x][y];
	map[x][y] = temp;
	x = nextx, y = nexty;
}
void playchoice()
{
	void AI();
	int t = 0;
	char i;
try_again:
	while (!kbhit())
	{
		i = getch();
		if (i == up || i == down || i == left || i == right || i == ok)
			break;
	}
	while (kbhit())
	{
		i = getch();
	}


	switch (i)
	{
	case left:             
		nextx = x;
		if (y == 4)
			goto try_again;
		else
			nexty = y - 1;
		if (map[x][y] == 1 || map[x][y] == 0)
		{
			if (!(map[nextx][nexty] == 1 || map[nextx][nexty] == 0))
				map[nextx][nexty] = 3;
			x = nextx, y = nexty;
			break;
		}
		if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
		{
			map[x][y] = 4;
			x = nextx, y = nexty;
			break;
		}
		swap(); break;
	case right:
		nextx = x;
		if (y == H - 5)
			goto try_again;
		else
			nexty = y + 1;
		if (map[x][y] == 1 || map[x][y] == 0)
		{
			if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
				;
			else
				map[nextx][nexty] = 3;
			x = nextx, y = nexty;
			break;
		}
		if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
		{
			map[x][y] = 4;
			x = nextx, y = nexty;
			break;
		}
		swap(); break;
	case up:
		if (x == 4)
			goto try_again;
		else
			nextx = x - 1;
		nexty = y;
		if (map[x][y] == 1 || map[x][y] == 0)
		{
			if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
				;
			else
				map[nextx][nexty] = 3;
			x = nextx, y = nexty;
			break;
		}
		if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
		{
			map[x][y] = 4;
			x = nextx, y = nexty;
			break;
		}
		swap(); break;
	case down:
		if (x == H - 5)
			goto try_again;
		else
			nextx = x + 1;
		nexty = y;
		if (map[x][y] == 1 || map[x][y] == 0)
		{
			if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
				;
			else
				map[nextx][nexty] = 3;
			x = nextx, y = nexty;
			break;
		}
		if (map[nextx][nexty] == 1 || map[nextx][nexty] == 0)
		{
			map[x][y] = 4;
			x = nextx, y = nexty;
			break;
		}
		swap();
		break;
	case ok:
		if (map[x][y] == 0 || map[x][y] == 1)
			goto try_again;
		else
		{
			map[x][y] = 1;
			system("cls");
			drawMap();
			//Sleep(800);
			AI();
			system("cls");
			drawMap();
			return;
		}
		break;
	default:break;
	}
	system("cls");
	drawMap();
}
int iswin()
{
	int i, j, time = 1, xi, yi;
	for (i = 4; i < H - 4; i++)
		for (j = 4; j < H - 4; j++)
		{
			if (map[i][j] == 1 || map[i][j] == 0)
			{
				if (map[i][j] == 0)
					wint = 0;
				else
					wint = 1;
				xi = i, yi = j;
				while (yi < H - 4 && yi>3)
				{
					yi++;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3)
				{
					yi--;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3)
				{
					xi++;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3)
				{
					xi--;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3 && yi < H - 4 && yi>3)
				{
					xi++, yi++;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3 && yi < H - 4 && yi>3)
				{
					xi++, yi--;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3 && yi < H - 4 && yi>3)
				{
					xi--, yi--;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
				xi = i, yi = j;
				while (xi < H - 4 && xi>3 && yi < H - 4 && yi>3)
				{
					xi--, yi++;
					if (map[xi][yi] == wint)
					{
						time++;
						if (time == 5)
							return 0;
					}
					else break;
				}
				time = 1;
			}
		}
	return 1;
}
void Evaluate()
{
	int i, j, score = 0, coord[H * H][2] = { 0 }, max = 0, t = 0;
	for (i = 4; i < H - 4; i++)
	{
		for (j = 4; j < H - 4; j++)
		{
			if (map[i][j] == 4)
			{
				if (map[i + 1][j] == now || map[i][j + 1] == now || map[i + 1][j + 1] == now || map[i - 1][j + 1] == now || map[i + 1][j - 1] == now || map[i - 1][j - 1] == now || map[i][j - 1] == now || map[i - 1][j] == now)   //����˸��������
				{
					//�һ�һ
					if (map[i][j + 1] == now && map[i][j + 2] == 4)
						score += 20;
					//����һ
					if (map[i][j + 1] == now && map[i][j + 2] == 9 || map[i][j + 1] == now && map[i][j + 2] == you)
						score += 4;
					//�һ��
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == 4)
						score += 400;
					//������
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == 9 || map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == you)
						score += 90;
					//�һ���
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == 4)
						score += 6000;
					//������
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == you || map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == 9)
						score += 800;
					//�һ���
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == now && map[i][j + 5] == 4)
						score += 20000;
					//������
					if (map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == now && map[i][j + 5] == you || map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == now && map[i][j + 4] == now && map[i][j + 5] == 9)
						score += 10000;
					//���һ
					if (map[i][j - 1] == now && map[i][j - 2] == 4)
						score += 20;
					//����һ
					if (map[i][j - 1] == now && map[i][j - 2] == you || map[i][j - 1] == 0 && map[i][j - 2] == 9)
						score += 4;
					//����
					if (map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == 4)
						score += 400;
					//������
					if (map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == you || map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == 9)
						score += 90;
					//�����
					if (map[i][j - 1] == you && map[i][j - 2] == you && map[i][j - 3] == you && map[i][j - 4] == 4)
						score += 6000;
					//������
					if (map[i][j - 1] == 0 && map[i][j - 2] == 0 && map[i][j - 3] == 0 && map[i][j - 4] == you || map[i][j - 1] == 0 && &map[i][j - 2] == 0 && map[i][j - 3] == 0 && map[i][j - 4] == 9)
						score += 800;
					//�����
					if (map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == now && map[i][j - 4] == now && map[i][j - 5] == 4)
						score += 20000;
					//������
					if (map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == now && map[i][j - 4] == now && map[i][j - 5] == you || map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == now && map[i][j - 4] == now && map[i][j - 5] == 9)
						score += 10000;
					//�»�һ
					if (map[i + 1][j] == now && map[i + 2][j] == 4)
						score += 20;
					//����һ
					if (map[i + 1][j] == now && map[i + 2][j] == you || map[i + 1][j] == now && map[i + 2][j] == 9)
						score += 4;
					//�»��
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == 4)
						score += 400;
					//������
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == 9 || map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == you)
						score += 90;
					//�»���
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == 4)
						score += 6000;
					//������
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == you || map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == 9)
						score += 800;
					//�»���
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == now && map[i + 5][j] == 4)
						score += 20000;
					//������
					if (map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == now && map[i + 5][j] == you || map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == now && map[i + 4][j] == now && map[i + 5][j] == 9)
						score += 10000;
					//�ϻ�һ
					if (map[i - 1][j] == now && map[i - 2][j] == 4)
						score += 20;
					//����һ
					if (map[i - 1][j] == now && map[i - 2][j] == you || map[i - 1][j] == now && map[i - 2][j] == 9)
						score += 4;
					//�ϻ��
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i][j - 3] == 4)
						score += 400;
					//������
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == 9 || map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == you)
						score += 90;
					//�ϻ���
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == 4)
						score += 6000;
					//������
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == you || map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == 9)
						score += 800;
					//�ϻ���
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == now && map[i - 5][j] == 4)
						score += 20000;
					//������
					if (map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == now && map[i - 5][j] == you || map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == now && map[i - 4][j] == now && map[i - 5][j] == 9)
						score += 10000;
					//���»�һ
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == 4)
						score += 20;
					//������һ
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == 9 || map[i + 1][j + 1] == now && map[i + 2][j + 2] == you)
						score += 4;
					//���»��
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == 4)
						score += 400;
					//��������
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == 9 || map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == you)
						score += 90;
					//���»���
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == 4)
						score += 6000;
					//��������
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == you || map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == 9)
						score += 800;
					//���»���
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == now && map[i + 5][j + 5] == 4)
						score += 20000;
					//��������
					if (map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == now && map[i + 5][j + 5] == you || map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == now && map[i + 4][j + 4] == now && map[i + 5][j + 5] == 9)
						score += 10000;
					//���ϻ�һ
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == 4)
						score += 20;
					//������һ
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == 9 || map[i - 1][j - 1] == now && map[i - 2][j - 2] == you)
						score += 4;
					//���ϻ��
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == 4)
						score += 400;
					//��������
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == 9 || map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == you)
						score += 90;
					//���ϻ���
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == 4)
						score += 6000;
					//��������
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == you || map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == 9)
						score += 800;
					//���ϻ���
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == now && map[i - 5][j - 5] == 4)
						score += 20000;
					//��������
					if (map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == now && map[i - 5][j - 5] == you || map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == now && map[i - 4][j - 4] == now && map[i - 5][j - 5] == 9)
						score += 10000;
					//���»�һ
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == 4)
						score += 20;
					//������һ
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == you || map[i + 1][j - 1] == now && map[i + 2][j - 2] == 9)
						score += 4;
					//���»��
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == 4)
						score += 400;
					//��������
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == 9 || map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == you)
						score += 90;
					//���»���
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == 4)
						score += 6000;
					//��������
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == you || map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == 9)
						score += 800;
					//���»���
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == now && map[i + 5][j - 5] == 4)
						score += 20000;
					//��������
					if (map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == now && map[i + 5][j - 5] == you || map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == now && map[i + 4][j - 4] == now && map[i + 5][j - 5] == 9)
						score += 10000;
					//���ϻ�һ
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == 4)
						score += 20;
					//������һ
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == you || map[i - 1][j + 1] == now && map[i - 2][j + 2] == 9)
						score += 4;
					//���ϻ��
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == 4)
						score += 400;
					//��������
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == 9 || map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == you)
						score += 90;
					//���ϻ���
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == 4)
						score += 6000;
					//��������
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == you || map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == 9)
						score += 800;
					//���ϻ���
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == now && map[i - 5][j + 5] == 4)
						score += 20000;
					//��������
					if (map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == now && map[i - 5][j + 5] == you || map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == now && map[i - 4][j + 4] == now && map[i - 5][j + 5] == 9)
						score += 10000;
					if (
						map[i][j - 1] == now && map[i][j - 2] == now && map[i][j - 3] == 4 && map[i][j + 1] == now && map[i][j + 2] == 4 ||
						map[i][j + 1] == now && map[i][j + 2] == now && map[i][j + 3] == 4 && map[i][j - 1] == now && map[i][j - 2] == 4 ||
						map[i - 1][j] == now && map[i - 2][j] == now && map[i - 3][j] == 4 && map[i + 1][j] == now && map[i + 2][j] == 4 ||
						map[i + 1][j] == now && map[i + 2][j] == now && map[i + 3][j] == 4 && map[i - 1][j] == now && map[i - 2][j] == 4 ||
						map[i - 1][j - 1] == now && map[i - 2][j - 2] == now && map[i - 3][j - 3] == 4 && map[i + 1][j + 1] == now && map[i + 2][j + 2] == 4 ||
						map[i + 1][j + 1] == now && map[i + 2][j + 2] == now && map[i + 3][j + 3] == 4 && map[i - 1][j - 1] == now && map[i - 2][j - 2] == 4 ||
						map[i + 1][j - 1] == now && map[i + 2][j - 2] == now && map[i + 3][j - 3] == 4 && map[i - 1][j + 1] == now && map[i - 2][j + 2] == 4 ||
						map[i - 1][j + 1] == now && map[i - 2][j + 2] == now && map[i - 3][j + 3] == 4 && map[i + 1][j - 1] == now && map[i + 2][j - 2] == 4)
						score += 5580;
				}
			}

			//�»�һ
			if (score < max)
				score = 0;
			if (score == max)
			{
				t++;
				coord[t][0] = i, coord[t][1] = j;
				score = 0;
			}
			if (score > max)
			{
				t = 0;
				coord[t][0] = i, coord[t][1] = j;
				max = score;
				score = 0;
			}
		}
	}

	if (turn == 1)
	{
		maxm = max;
		i = rand() % (t + 1);
		maxmcoordx = coord[i][0];
		maxmcoordy = coord[i][1];
		turn = 2;
		now = 1, you = 0;
		Evaluate();
	}
	else
	{
		maxy = max;
		i = rand() % (t + 1);
		maxycoordx = coord[i][0];
		maxycoordy = coord[i][1];
	}

}
void AI()
{
	now = 0, you = 1;
	turn = 1;
	Evaluate();
	if (maxm > maxy)
		map[maxmcoordx][maxmcoordy] = 0;
	if (maxm < maxy)
		map[maxycoordx][maxycoordy] = 0;
	if (maxm == maxy)
	{
		now = rand() % 1;
		if (now == 1)
			map[maxycoordx][maxycoordy] = 0;
		else
			map[maxmcoordx][maxmcoordy] = 0;


	}
	system("cls");
	drawMap();
}
void Run()
{
	while (iswin())
		playchoice();
	if (wint == 1)
		printf("\n\t\t\t����Ӯ�ˣ�\n");
	else
		printf("\n\t\t\t����Ӯ�ˣ�\n");
	printf("\t\t\t��Ϸ������\n\t\t����������¿�ʼ\n");
	x = getch();
}
int main()
{
	printf("\n\n\n\tʹ��wsad�ƶ���j����\n");
	Sleep(800);
	system("cls");
	while (!kbhit())
	{
		init_map_array();
		drawMap();
		Run();
	}
	return 0;
}
