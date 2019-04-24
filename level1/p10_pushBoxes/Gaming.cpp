#include <time.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "game.h"

struct Player
{
	int x;
	int y;
}player;

struct Des
{
	int x;
	int y;
}DesPos[10];

bool wall[15][15];
bool des[15][15];
bool box[15][15];

int Gaming(char Map[][15], int i, bool *back, int level);

int Gaming(char Map[][15], int i, bool *back, int level)
{
	int x, y;
    Restart:
	memset(wall, 0, sizeof(wall));
	memset(des, 0, sizeof(des));
	memset(box, 0, sizeof(box));
	system("cls");
	int j, k;
	int m;
	int win;
	int score = 5000;
	int NumOfBox = 0;
	bool found = false;
	for (j = 0; j < i; ++j)
	{
		printf("%s", Map[j]);
		for (k = 0; k < 15; ++k)
		{
			switch (Map[j][k])
			{
			case '#':
				wall[j][k] = true;
				break;
			case 'D':
				des[j][k] = true;
				DesPos[NumOfBox].x = k;
				DesPos[NumOfBox].y = j;
				++NumOfBox;
				break;
			case 'O':
				player.x = k;
				player.y = j;
				break;
			case 'X':
				box[j][k] = true;
			}
		}
	}
	printf("\n---------------\n");
	printf("Use directtion keys to control...\n");
	printf("Press R to restart...\n");
	printf("Press S to save your level...\n");
	printf("Press Esc back to the menu...\n");

	CONSOLE_SCREEN_BUFFER_INFO cInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cInfo);
	x = cInfo.dwCursorPosition.X;
	y = cInfo.dwCursorPosition.Y;

	clock_t t = clock();
	while (GetKeyState(VK_ESCAPE) >= 0)
	{
		win = 0;
		if (GetKeyState(82) < 0)
		{
			goto Restart;
		}
		if (GetKeyState(VK_UP) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y - 1][player.x])
				{
					if (box[player.y - 1][player.x])
					{
						if (!wall[player.y - 2][player.x] && !box[player.y - 2][player.x])
						{
							PrintX(player.x, player.y - 2);
							PrintO(player.x, player.y - 1);
							if (des[player.y][player.x])
							{
								PrintD(player.x, player.y);
							}
							else
							{
								PrintSpace(player.x, player.y);
							}
							box[player.y - 1][player.x] = false;
							box[player.y - 2][player.x] = true;
							--player.y;
							score -= 10;
						}
					}
					else
					{
						PrintO(player.x, player.y - 1);
						if (des[player.y][player.x])
						{
							PrintD(player.x, player.y);
						}
						else
						{
							PrintSpace(player.x, player.y);
						}
						--player.y;
						score -= 10;
					}
				}
			}
		}
		if (GetKeyState(VK_RIGHT) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y][player.x + 1])
				{
					if (box[player.y][player.x + 1])
					{
						if (!wall[player.y][player.x + 2] && !box[player.y][player.x + 2])
						{
							PrintX(player.x + 2, player.y);
							PrintO(player.x + 1, player.y);
							if (des[player.y][player.x])
							{
								PrintD(player.x, player.y);
							}
							else
							{
								PrintSpace(player.x, player.y);
							}
							box[player.y][player.x + 1] = false;
							box[player.y][player.x + 2] = true;
							++player.x;
							score -= 10;
						}
					}
					else
					{
						PrintO(player.x + 1, player.y);
						if (des[player.y][player.x])
						{
							PrintD(player.x, player.y);
						}
						else
						{
							PrintSpace(player.x, player.y);
						}
						++player.x;
						score -= 10;
					}
				}
			}
		}
		if (GetKeyState(VK_LEFT) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y][player.x - 1])
				{
					if (box[player.y][player.x - 1])
					{
						if (!wall[player.y][player.x - 2] && !box[player.y][player.x - 2])
						{
							PrintX(player.x - 2, player.y);
							PrintO(player.x - 1, player.y);
							if (des[player.y][player.x])
							{
								PrintD(player.x, player.y);
							}
							else
							{
								PrintSpace(player.x, player.y);
							}
							box[player.y][player.x - 1] = false;
							box[player.y][player.x - 2] = true;
							--player.x;
							score -= 10;
						}
					}
					else
					{
						PrintO(player.x - 1, player.y);
						if (des[player.y][player.x])
						{
							PrintD(player.x, player.y);
						}
						else
						{
							PrintSpace(player.x, player.y);
						}
						--player.x;
						score -= 10;
					}
				}
			}
		}
		if (GetKeyState(VK_DOWN) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (!wall[player.y + 1][player.x])
				{
					if (box[player.y + 1][player.x])
					{
						if (!wall[player.y + 2][player.x] && !box[player.y + 2][player.x])
						{
							PrintX(player.x, player.y + 2);
							PrintO(player.x, player.y + 1);
							if (des[player.y][player.x])
							{
								PrintD(player.x, player.y);
							}
							else
							{
								PrintSpace(player.x, player.y);
							}
							box[player.y + 1][player.x] = false;
							box[player.y + 2][player.x] = true;
							++player.y;
							score -= 10;
						}
					}
					else
					{
						PrintO(player.x, player.y + 1);
						if (des[player.y][player.x])
						{
							PrintD(player.x, player.y);
						}
						else
						{
							PrintSpace(player.x, player.y);
						}
						++player.y;
						score -= 10;
					}
				}
			}
		}
		if (GetKeyState(83))
		{
			Save(level);
			SetPosition(x, y);
			printf("Saved!!!\n");
		}
		for (m = 0; m < NumOfBox; ++m)
		{
			if (box[DesPos[m].y][DesPos[m].x])
			{
				++win;
			}
		}
		if (win == NumOfBox)
		{
			system("cls");
			SetPosition(5, 4);
			printf("You win!!!\n");
			SaveScore(level, score);
			printf("Press Enter to continue...\n");
			return score;
		}
	}
	back[0] = true;
	printf("%d\n", back[0]);
	return score;
}