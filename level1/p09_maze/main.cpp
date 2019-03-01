#include"drawGraphics.h"
#include<windows.h>
#include<iostream>
#include<conio.h>
#include<cstdio>
#include<ctime>

int vis[W][H];

void dfs(int x, int y)
{
	G[x][y] = ROAD;
	vis[x][y] = 1;

	int rec[4][2];
	for (int s = 0; s < 4; s++)
	{
		rec[s][0] = rand();
		rec[s][1] = s;
	}
	for (int s = 0; s < 4; s++)
	{
		for (int t = s; t < 4; t++)
		{
			if (rec[s][0] > rec[t][0])
			{
				std::swap(rec[s][0], rec[t][0]);
				std::swap(rec[s][1], rec[t][1]);
			}
		}
	}
	for (int s = 0; s < 4; s++)
	{
		int dx = D[rec[s][1]][0];
		int dy = D[rec[s][1]][1];
		int nextX = x + dx * 2;
		int nextY = y + dy * 2;
		if (nextX < 0 || nextY < 0 || nextX >= W || nextY >= H) continue;
		if (vis[nextX][nextY]) continue;
		G[x + dx][y + dy] = ROAD;
		dfs(nextX, nextY);
	}
}

void generateMap()
{
	clear();
	drawSquare(0, 0, H-1, W-1, WALL);
	dfs(1, 1);
}

int runGame()
{
	Object player, theExit;
	player.set(1, 1, '@');
	theExit.set(W-2, H-2, 'E');
	theExit.draw(theExit.symbol);
	int mv;
	while (!cmpPos(player, theExit))
	{
		if (kbhit())
		{
			cls();
			mv = transKeyval(getch());
			if (player.canMove(mv))
			{
				player.draw(ROAD);
				player.move(mv);
			}
			player.draw(player.symbol);
			print();
		}
	}
}

int main()
{
	srand(time(NULL));
	system("mode con: cols=84 lines=34");
	system("title Maze Game");
	generateMap();
	runGame();
}
