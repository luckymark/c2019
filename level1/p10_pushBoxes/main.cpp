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

void makeMove(int id, int mv)
{
	if (~id)
	{
		if (!box[id].canMove(mv)) return;
		if (getBoxID(box[id].x + DX[mv], box[id].y + DY[mv]) != -1) return;
		if (G[box[id].x][box[id].y] == TARGET)
		{
			print(box[id].x, box[id].y, TARGET);
			boxFilled--;
		}
		print(box[id].x, box[id].y, PLAYER);
		box[id].move(mv);
		if (G[box[id].x][box[id].y] == TARGET) boxFilled++;
		print(box[id].x, box[id].y, BOX);
		print(player.x, player.y, ROAD);
		player.move(mv);
		print(player.x, player.y, PLAYER);
		step++;
	}
	else
	{
		if (!player.canMove(mv)) return;
		char tmp = G[player.x][player.y] != TARGET ? ROAD : TARGET;
		print(player.x, player.y, tmp);
		player.move(mv);
		print(player.x, player.y, PLAYER);
		step++;
	}
}

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
			int id = getBoxID(player.x + DX[mv], player.y + DY[mv]);
			makeMove(id, mv);
		}
	}
	//printSquare(0, 0, W-1, H-1, ' ');
	moveCursor(0, 11);
	printf("µÅ¡üµÅ¨JµÅ¡úµÅ¨KµÅ¡ýµÅ¡úµÅ¨JµÅ¡ü\n");
	printf("Total steps: %d\n", step);
	FILE *p = fopen("score/score.txt", "w+");
	fprintf(p, "%d", step);
}

int main()
{
	runGame();
}
