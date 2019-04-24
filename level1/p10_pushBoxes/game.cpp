#include "game.h"
#include <time.h>
#include <stdio.h>
#include <Windows.h>


void game();

char Map[15][15];
bool back[2];

void game()
{
	int i = 1;
	int line;
	BackToMenu:
	int score = 0;
	int ScoreSum = 0;
	back[0] = false;
	int SON = StartGame();
	if (SON == 0)
	{
		return;
	}
	i = SON;
	for (i; i <= 3; i++)
	{
		back[0] = false;
		line = LoadMap(i, Map);
		score = Gaming(Map, line, back, i);
		ScoreSum += score;
		if (!back[0])
		{
			while (GetKeyState(VK_RETURN) >= 0);
		}
		else
		{
			break;
		}
	}
	if (back[0])
	{
		system("cls");
		goto BackToMenu;
	}
	system("cls");
	printf("Your final score is %d\n", ScoreSum);
	system("pause");
	goto BackToMenu;
	return;
}