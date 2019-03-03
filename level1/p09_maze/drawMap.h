#include<cstring>
#include<cstdlib>
#include<cstdio>


bool cmpPos(Object a, Object b)
{
	return a.x == b.x && a.y == b.y;
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

void printMap()
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
