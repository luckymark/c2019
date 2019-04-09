#include<windows.h>
#include<stdio.h>
#include"size.h"
void printchange(char map[HEIGHT][WIDTH], int x, int y, int f, const int goal[5][2])
//map,position,direction,goal
{
	HANDLE handle;//���
	handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ʼ�����
	COORD pos = { 0,0 };//��ʼ�����λ��
	CONSOLE_CURSOR_INFO cinfo;//����̨�����Ϣ
	GetConsoleCursorInfo(handle, &cinfo);//��ȡ����̨�����Ϣ
	cinfo.bVisible = 0;//���ؿ���̨���
	cinfo.dwSize = 1;//����ϸ
	SetConsoleCursorInfo(handle, &cinfo);//���ÿ���̨�����Ϣ
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