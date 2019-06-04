#include<windows.h>
#include<stdio.h>
#include"size.h"
void printchange(char map[HEIGHT][WIDTH], int x, int y, int f, const int goal[5][2])
//map,position,direction,goal
{
	HANDLE handle;//句柄
	handle = GetStdHandle(STD_OUTPUT_HANDLE);//初始化句柄
	COORD pos = { 0,0 };//初始化光标位置
	CONSOLE_CURSOR_INFO cinfo;//控制台光标信息
	GetConsoleCursorInfo(handle, &cinfo);//获取控制台光标信息
	cinfo.bVisible = 0;//隐藏控制台光标
	cinfo.dwSize = 1;//光标粗细
	SetConsoleCursorInfo(handle, &cinfo);//设置控制台光标信息
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
	printf(" ");//ermove people
	switch (f) {
	case(80)://down
		if (map[y + 1][x] == 'B'/*Box*/) {
			pos.X = x;
			pos.Y = y + 2;
			SetConsoleCursorPosition(handle, pos);
			printf("B"/*Box*/);//print box
			map[y + 2][x] = 'B';//update box
		}
		map[y][x] = ' ';map[y + 1][x] = '*';//update people
		pos.X = x;
		pos.Y = y + 1;
		SetConsoleCursorPosition(handle, pos);
		printf("*");//print people
		break;
	case(72)://up
		if (map[y - 1][x] == 'B'/*Box*/) {
			pos.X = x;
			pos.Y = y - 2;
			SetConsoleCursorPosition(handle, pos);
			printf("B"/*Box*/);//print box
			map[y - 2][x] = 'B';//update box
		}
		map[y][x] = ' ';map[y - 1][x] = '*'; //update people
		pos.X = x;
		pos.Y = y - 1;
		SetConsoleCursorPosition(handle, pos);
		printf("*");//print people
		break;
	case(75)://left
		if (map[y][x - 1] == 'B'/*Box*/) {
			pos.X = x - 2;
			pos.Y = y;
			SetConsoleCursorPosition(handle, pos);
			printf("B"/*Box*/);//print box
			 map[y][x - 2] = 'B';//update box
		}
		map[y][x] = ' ';map[y][x - 1] = '*';//update people
		pos.X = x - 1;
		pos.Y = y;
		SetConsoleCursorPosition(handle, pos);
		printf("*");//print people
		break;
	case(77)://tight
		if (map[y][x + 1] == 'B'/*Box*/) {
			pos.X = x + 2;
			pos.Y = y;
			SetConsoleCursorPosition(handle, pos);
			printf("B"/*Box*/);//print box
			 map[y][x + 2] = 'B';//update box
		}
		map[y][x] = ' '; map[y][x + 1] = '*'; //update people;
		pos.X = x + 1;
		pos.Y = y;
		SetConsoleCursorPosition(handle, pos);
		printf("*");//print people
		break;
	}
	for (int i = 1; goal[i][0] != 0 ; i++) {
		if (map[goal[i][1]][goal[i][0]] == ' ') {
			pos.X = goal[i][0];
			pos.Y = goal[i][1];
			SetConsoleCursorPosition(handle, pos);
			printf("!");
		}
	}
}