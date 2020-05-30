#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdio>
#include<ctime>

#include"definition.h"
#include"drawMap.h"
#include"mapGenerate.h"
#include"key.h"
#include"display.h"

int runGame()
{
	Object player, theExit;
	player.set(1, H-2, '@');
	theExit.set(W-2, 1, 'E');
	theExit.draw(theExit.symbol);
	int mv;
	printMap();
	while (!cmpPos(player, theExit))
	{
		if (kbhit())
		{
			mv = transKeyval(getch());
			if (player.canMove(mv))
			{
				print(player.x, player.y, TRAIL);
				player.move(mv);
			}
			print(player.x, player.y, PLAYER);
		}
	}
	printSquare(0, 0, W-1, H-1, ' ');
	char str[] = "You win!!";
	printString(0, 0, str);
}

int main()
{
	srand(time(NULL));
	system("mode con: cols=84 lines=34");
	system("title Maze Game");
	generateMap();
	runGame();
}
