#include<cstring>
#include<cstdlib>
#include<cstdio>

const int W = 81, H = 31;

char G[W+1][H];

char WALL = '#', ROAD = ' ';

int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};



struct Object
{
	int x, y;
	char symbol;
	Object set(int posX, int posY, char ch)
	{
		x = posX, y = posY;
		symbol = ch;
	}
	bool canMove(int dir)
	{
		return G[x + DX[dir]][y + DY[dir]] != WALL;
	}
	void move(int dir)
	{
		x += DX[dir], y += DY[dir];
	}
	void draw(char ch)
	{
		G[x][y] = ch;
	}
};

bool cmpPos(Object a, Object b)
{
	return a.x == b.x && a.y == b.y;
}

int transKeyval(int keyVal)
{
	switch (keyVal)
	{
		case 75:
			return 0;
		case 72:
			return 3;
		case 77:
			return 2;
		case 80:
			return 1;
	}
}


void cls()
{
	system("cls");
}

void clear()
{
	for (int s = 0; s < H; s++)
	{
		for (int t = 0; t < W; t++)
			G[t][s] = ROAD;
		G[W][s] = '\n';
	}
}

void print()
{
	for (int s = 0; s < H; s++)
		for (int t = 0; t < W+1; t++)
			printf("%c", G[t][s]);
}

void drawPoint(int x, int y, char ch)
{
	G[x][y] = ch;
}

void drawLine(int st, int nd, int lv, char ch, char opt)
{
	if (opt == '|')
		for (int s = st; s <= nd; s++)
			G[lv][s] = ch;
	else
		for (int t = st; t <= nd; t++)
			G[t][lv] = ch;
}

void drawSquare(int startX, int startY, int endX, int endY, char ch)
{
	for (int s = startX; s <= endX; s++)
		for (int t = startY; t <= endY; t++)
			G[t][s] = ch;
}

void drawString(int x, int y, char *ch)
{
	for (int s=x; s<=strlen(ch); s++)
		G[s][y] = ch[s];
}
