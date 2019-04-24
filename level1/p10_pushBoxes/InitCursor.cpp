#include <Windows.h>

void InitCursor();

void InitCursor()
{
	CONSOLE_CURSOR_INFO cursor = { 100, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}