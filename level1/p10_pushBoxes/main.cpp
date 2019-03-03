#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdio>
#include<vector>
using std::vector;

#include"definition.h"
#include"map.h"
#include"key.h"
#include"display.h"

int step = 0;

int runGame()
{
	loadMap();
	printMap();
	for (int s = 0; s < box.size(); s++)
		print(box[s].x, box[s].y, BOX);
	print(player.x, player.y, PLAYER);
	while (boxFilled < boxTotal)
	{
		if (kbhit())
		{
			int mv = transKeyval(getch());
			int boxID = getBoxID(player.x + DX[mv], player.y + DY[mv]);
			if (~boxID)
			{
				if (box[boxID].canMove(mv) && getBoxID(box[boxID].x + DX[mv], box[boxID].y + DY[mv]) == -1)
				{
					if (G[box[boxID].x][box[boxID].y] == TARGET)
					{
						print(box[boxID].x, box[boxID].y, TARGET);
						boxFilled--;
					}
					print(box[boxID].x, box[boxID].y, PLAYER);
					box[boxID].move(mv);
					if (G[box[boxID].x][box[boxID].y] == TARGET) boxFilled++;
					print(box[boxID].x, box[boxID].y, BOX);
					print(player.x, player.y, ROAD);
					player.move(mv);
					print(player.x, player.y, PLAYER);
					step++;
				}
			}
			else
			{
				if (player.canMove(mv))
				{
					char tmp;
					if (G[player.x][player.y] != TARGET) tmp = ROAD;
					else tmp = TARGET;
					print(player.x, player.y, tmp);
					player.move(mv);
					print(player.x, player.y, PLAYER);
					step++;
				}
			}
		}
	}
	printSquare(0, 0, W-1, H-1, ' ');
	char str[] = "You win!!";
	printString(0, 0, str);
	printf("\nTotal steps: %d\n", step);
	FILE *p = fopen("score/score.txt", "w+");
	fprintf(p, "%d", step);
}

int main()
{
	system("mode con: cols=84 lines=34");
	system("title PushBoxes");
	runGame();
}
