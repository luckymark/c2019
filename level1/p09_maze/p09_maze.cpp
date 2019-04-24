#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

char map[30][30];

bool wall[30][30];

struct Player
{
	int x;
	int y;
}player;

struct Des
{
	int x;
	int y;
}DesPos;

int StartGame();

void SetPosition(int x, int y);

void PrintSpace(int x, int y);

void PrintX(int x, int y);

void PrintO(int x, int y);

void PrintD(int x, int y);

int LoadMap(char Map[][30]);

void Gaming(char Map[][30], int i);

int main()
{
	CONSOLE_CURSOR_INFO cursor = { 100, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

	int line;
BackToMenu:
	int SON = StartGame();
	if (SON == 0)
	{
		return 0;
	}
	line = LoadMap(map);
	Gaming(map, line);
	system("cls");
	goto BackToMenu;
}

int StartGame()
{
	system("cls");
	printf("---------------------------------\n");
	printf("\n\n\n");
	printf("             Push Boxes\n\n");
	printf("            1. NEW GAME\n");
	printf("            2. EXIT GAME\n");
	printf("\n\n\n");
	printf("---------------------------------\n");
	printf("Press Enter to choose...\n");
	SetPosition(5, 6);
	printf("->");
	clock_t t = clock();
	const int x = 5;
	int y = 6;
	while (GetKeyState(VK_RETURN) >= 0)
	{
		if (GetKeyState(VK_UP) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (y != 6)
				{
					PrintSpace(x, y);
					PrintSpace(x + 1, y);
					--y;
					SetPosition(x, y);
					printf("->");
				}
				else
				{
					PrintSpace(x, y);
					PrintSpace(x + 1, y);
					y = 7;
					SetPosition(x, y);
					printf("->");
				}
			}
		}
		else if (GetKeyState(VK_DOWN) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (y != 7)
				{
					PrintSpace(x, y);
					PrintSpace(x + 1, y);
					++y;
					SetPosition(x, y);
					printf("->");
				}
				else
				{
					PrintSpace(x, y);
					PrintSpace(x + 1, y);
					y = 6;
					SetPosition(x, y);
					printf("->");
				}
			}
		}
	}
	switch (y)
	{
	case 6:return 1; break;
	case 7:return 0;
	}
}

void SetPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PrintSpace(int x, int y)
{
	SetPosition(x, y);
	printf(" ");
}

void PrintX(int x, int y)
{
	SetPosition(x, y);
	printf("X");
}

void PrintO(int x, int y)
{
	SetPosition(x, y);
	printf("O");
}

void PrintD(int x, int y)
{
	SetPosition(x, y);
	printf("D");
}

int LoadMap(char Map[][30])
{
	int i = 0;
	FILE *fp;
	fp = fopen("Maze.txt", "r");
	if (fp == NULL)
	{
		printf("Something wrong!\n");
		system("pause");
		return 0;
	}
	while (!feof(fp))
	{
		fgets(Map[i], 30, fp);
		++i;
	}
	fclose(fp);
	return i;
}

void Gaming(char Map[][30], int i)
{
	int x, y;
	int k;
	int j;
	memset(wall, 0, sizeof(wall));
	system("cls");
	for (j = 0; j < i; ++j)
	{
		printf("%s", Map[j]);
		for (k = 0; k < 30; ++k)
		{
			switch (Map[j][k])
			{
			case '#':
				wall[j][k] = true;
				break;
			case 'D':
				DesPos.x = k;
				DesPos.y = j;
				break;
			case 'O':
				player.x = k;
				player.y = j;
				break;
			}
		}
	}
	printf("\n---------------\n");
	printf("Use directtion keys to control...\n");
	printf("Press Esc back to the menu...\n");
	clock_t t = clock();
	while (GetKeyState(VK_ESCAPE) >= 0)
	{
		if (GetKeyState(VK_UP) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				
				if (!wall[player.y - 1][player.x] && player.y != 0)
				{
					PrintO(player.x, player.y - 1);
					PrintSpace(player.x, player.y);
					--player.y;
				}
			}
		}
		else if (GetKeyState(VK_DOWN) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y + 1][player.x])
				{
					PrintO(player.x, player.y + 1);
					PrintSpace(player.x, player.y);
					++player.y;
				}
			}
		}
		else if (GetKeyState(VK_LEFT) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y][player.x - 1])
				{
					PrintO(player.x - 1, player.y);
					PrintSpace(player.x, player.y);
					--player.x;
				}
			}
		}
		else if (GetKeyState(VK_RIGHT) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y][player.x + 1])
				{
					PrintO(player.x + 1, player.y);
					PrintSpace(player.x, player.y);
					++player.x;
				}
			}
		}
		if (player.x == DesPos.x&&player.y == DesPos.y)
		{
			system("cls");
			printf("You win!!!!\nPress Shift to back to the menu...\n");
			while (GetKeyState(VK_SHIFT) >= 0);
			return;
		}
	}
	return;
}