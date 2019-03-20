#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MINN 10
#define MAXN 30

char Maze[MAXN][MAXN];
int ToX[4] = { 0,0,1,-1 };
int ToY[4] = { 1,-1,0,0 };
int h, w, Vis[MAXN][MAXN];
int DesX, DesY, NowX, NowY;

int GetRand(int LowerBound, int UpperBound)
{
	return rand() % (UpperBound - LowerBound + 1) + LowerBound;
}

int Check(int x, int y)
{
	return Vis[x][y] == 0 && Maze[x][y] != '#';
}

int Dfs(int x, int y)
{
	if (!Check(x, y))return 0;
	if (x == DesX && y == DesY)return 1;
	Vis[x][y] = 1;
	for (int i = 0; i < 4; ++i)
	{
		if (Dfs(x + ToX[i], y + ToY[i]))
			return 1;
	}
	return 0;
}

void GenerateNewMaze()
{
	memset(Vis, 0, sizeof(Vis));
	h = GetRand(MINN, MAXN);
	w = GetRand(MINN, MAXN);
	if (h > w) { int tmp = h; h = w; w = tmp; }
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
		{
			if (GetRand(0, 2) == 0)Maze[i][j] = '#';
			else Maze[i][j] = ' ';
		}
	}
	for(int i=0;i<=h+1;++i)Maze[i][0]=Maze[i][w+1]='#';
	for(int i=0;i<=w+1;++i)Maze[0][i]=Maze[h+1][i]='#';
	DesX = h; DesY = w;
	NowX = 1; NowY = 1;
	Maze[DesX][DesY] = 'T';
	if (!Dfs(NowX, NowY))
		GenerateNewMaze();
}

void PrintMaze()
{
	for (int i = 0; i <= h+1; ++i)
	{
		for (int j = 0; j <= w+1; ++j)
		{
			if (i == NowX && j == NowY)printf("S");
			else printf("%c", Maze[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	unsigned char ch;
	srand(time(NULL));
	GenerateNewMaze();
	PrintMaze();
	memset(Vis, 0, sizeof(Vis));
	while (1)
	{
		if (_kbhit())
		{
			ch = _getch();
			if(ch==224)ch=_getch();
			if (ch == 72 && Check(NowX - 1, NowY))NowX--;
			if (ch == 80 && Check(NowX + 1, NowY))NowX++;
			if (ch == 75 && Check(NowX, NowY - 1))NowY--;
			if (ch == 77 && Check(NowX, NowY + 1))NowY++;
			system("cls"); PrintMaze();
			if (NowX == DesX && NowY == DesY)break;
		}
	}
	printf("Done\n");
	return 0;
}
