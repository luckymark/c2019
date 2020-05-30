#include<windows.h>
#include<cstdio>

void cls()
{
	system("cls");
}

void moveCursor(int x, int y)
{
	COORD pos = {x, y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void hideCursor()
{	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(handle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(handle, &cci);
}

void print(int x, int y, char ch)
{
	moveCursor(x, y);
	hideCursor();
	putchar(ch);
}

void printLine(int st, int nd, int lv, char ch, char opt)
{
	if (opt == '|')
		for (int s = st; s <= nd; s++)
			print(lv, s, ch);
	else
		for (int t = st; t <= nd; t++)
			print(t, lv, ch);
}

void printSquare(int startX, int startY, int endX, int endY, char ch)
{
	for (int s = startX; s <= endX; s++)
		for (int t = startY; t <= endY; t++)
			print(s, t, ch);
}

void printString(int x, int y, char *ch)
{
	for (int s=x; s<=strlen(ch); s++)
		print(s, y, ch[s]);
}
