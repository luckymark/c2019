#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAXN 100
#define EDGE 120
#define SPEED 10

void PrintStr(char s[], int x, int y)
{
	HANDLE hd;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hd, pos);
	printf("%s",s);
}

int main()
{
	char a[MAXN]="a";
	int x = 1, y = 0, dir = 1, len = strlen(a);
	PrintStr(a, 0, 0); Sleep(50);
	while (1)
	{
		system("cls");
		if (x == 0 || x == EDGE - len)
		{
			dir *= -1;
			y++;
		}
		x += dir;
		PrintStr(a, x, y);
		Sleep(SPEED);
	}
	return 0;
}
