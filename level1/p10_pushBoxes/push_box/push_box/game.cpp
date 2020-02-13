#include "game.h"

int win(char(*map)[15])//已经完成则返回1，没有则返回0
{
	int i, j;
	for (i = 0; i<15; i++)
	{
		for (j = 0;j<15; j++)
		{
			if (map[i][j] == target||map[i][j]==pt)
			{
				return 0;
			}
		}
	}
	return 1;
}

int move(char(*map)[15])
{
	game_menu();
	print(map);
	int score = 1000;
	while (!win(map))
	{
		int i, j;
		int row, line;
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
			{
				if (map[i][j] == player || map[i][j] == pt)
				{
					row = i;
					line = j;
					break;
				}
			}
		}

		char ch = _getch();
		switch (ch)
		{
		case 72:
			move_onstep(&map[row][line], &map[row - 1][line], &map[row - 2][line], &score);
			game_menu();
			print(map);
			score--;
			break;
		case 80:
			move_onstep(&map[row][line], &map[row + 1][line], &map[row + 2][line], &score);
			game_menu();
			print(map);
			score--;
			break;
		case 75:
			move_onstep(&map[row][line], &map[row][line - 1], &map[row][line - 2], &score);
			game_menu();
			print(map);
			score--;
			break;
		case 77:
			move_onstep(&map[row][line], &map[row][line + 1], &map[row][line + 2], &score);
			game_menu();
			print(map); 
			score--;
			break;
		case'r':return 0;
		case'R':return 0;
		}

	}
	if (win(map) == 1)
	{
		printf("Completed!");
		system("pause");
		return score;
	}
}

void move_onstep(char * play, char * forward1, char * forward2,int *score)
{
	//玩家当前的位置为H
	if (*play == player)
	{
		if (*forward1 == empty)
		{
			
			*play = empty;
			*forward1 = player; 
			
			return;
		}
		if (*forward1 == target)
		{
			*play = empty;
			*forward1 = pt;
			
			return;
		}
		if (*forward1 == box)
		{
			if (*forward2 == empty)
			{
				*forward2 = box;
				*forward1 = player;
				*play = empty;
				
				return;
			}
			if (*forward2 == target)
			{
				*forward2 = bt;
				*forward1 = player;
				*play = empty;
				
				return;
			}
		}
		if (*forward1 == bt)
		{
			if (*forward2 == empty)
			{
				*forward2 = box;
				*forward1 = pt;
				*play = empty;
				
				return;
			}
			if (*forward2 == target)
			{
				*forward2 = bt;
				*forward1 = pt;
				*play = empty;
				
				return;
			}
		}
	}
	//玩家当前的位置为h
	if (*play == pt)
	{
		if (*forward1 == empty)
		{
			*play = target;
			*forward1 = player;
			
			return;
		}
		if (*forward1 == target)
		{
			*play = target;
			*forward1 = pt;
			
			return;
		}
		if (*forward1 == box)
		{
			if (*forward2 == empty)
			{
				*forward2 = box;
				*forward1 = player;
				*play = target;
				
				return;
			}
			if (*forward2 == target)
			{
				*forward2 = bt;
				*forward1 = player;
				*play = target;
				
				return;
			}
		}
		if (*forward1 == bt)
		{
			if (*forward2 == empty)
			{
				*forward2 = box;
				*forward1 = pt;
				*play = target;
				
				return;
			}
			if (*forward2 == target)
			{
				*forward2 = bt;
				*forward1 = pt;
				*play = target;
				
				return;
			}
		}
	}
}		   

void main_menu(void)
{
	system("cls");
	printf("\tInput a number to start\n");
	printf("\t1:Easy game.\n");
	printf("\t2:Hard game.\n");
	printf("\tQ:Exit.");

	return;
}

void game_menu(void)
{
	system("cls");
	printf("\tUse direction keys to move.\n");
	printf("\tSymbols meaning:\n");
	printf("\tH:Player\n");
	printf("\tO:Boxes\n");
	printf("\t*:Walls\n");
	printf("\tT:Target\n");
	printf("\tC:Boxes on the target\n");
	printf("\th:Player on the target\n");
	printf("\n\tPress R to return to the main menu.\n\n");
	return;
}

void record(int number, int score)
{
	const char ch= '\n';
	if (number == 1)
	{
		FILE *fp = fopen("score1.txt", "a+");
		fwrite(&score, sizeof(int), 1, fp);
		fwrite(&ch, sizeof('\n'), 1, fp);
		fclose(fp);
	}
	if (number == 2)
	{
		FILE *fp = fopen("score2.txt", "a+");
		fwrite(&score, sizeof(int), 1, fp);
		fwrite(&ch, sizeof('\n'), 1, fp);
		fclose(fp);
	}
}
