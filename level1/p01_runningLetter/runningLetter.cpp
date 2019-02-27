#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void PrintStr(string s, int x, int y)
{
	HANDLE hd;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hd, pos);
	cout << s;
}

int main()
{
	string a = "a";
	const int EDGE = 120, SPEED = 10;
	int x = 1, y = 0, dir = 1, len = a.size();
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
