#include<windows.h>
#include<cstring>
#include<cstdio>

const int H = 20, W = 80;

char G[H][W+1];

int Sleeptime = 20;

void cls()
{
	system("cls");
}

void clear()
{
	for (int s = 0; s < H; s++)
	{
		for (int t = 0; t < W; t++)
			G[s][t] = ' ';
		G[s][W] = '\n';
	}
}

void print()
{
	for (int s = 0; s < H; s++)
		for (int t = 0; t < W+1; t++)
			printf("%c", G[s][t]);
}

void drawString(int x, int y, char *ch, int l)
{
	for (int s = 0; s <= l; s++)
		G[y][s+x] = ch[s];
}

int main()
{
	char a[30];
	scanf("%s", a);
	int Len = strlen(a);
	int x = 1, y = 2;
	int dx = 1, dy = 1;
	while (1)
	{
		x += dx, y += dy;
		if (x + Len >= W) dx = -1;
		if (y >= H) dy = -1;
		if (x <= 0) dx = 1;
		if (y <= 0) dy = 1;
		clear();
		cls();
		drawString(x, y, a, Len);
		print();
		Sleep(Sleeptime);
	}
}
