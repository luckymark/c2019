#include <stdio.h>
#include "game.h"
#include <Windows.h>
#include <time.h>

int StartGame();

int StartGame()
{
	system("cls");
	InitCursor();
	printf("---------------------------------\n");
	printf("\n\n\n");
	printf("             Push Boxes\n\n");
	printf("            1. NEW GAME\n");
	printf("            2. LOAD GAME\n");
	printf("            3. EXIT GAME\n");
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
					y = 8;
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
				if (y != 8)
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
	case 6:return 1;
	case 7:return LoadGame();
	case 8:return 0;
	}
}