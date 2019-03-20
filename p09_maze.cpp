/*
1.从这里开始作业变难了，首先是迷宫游戏的制作过程，我们首先是要生成迷宫，迷宫的生成有许多算法，这里采用回溯法。
2.生成迷宫的方法找到了之后，我们需要采用手段让静态的迷宫动起来，那么方法是什么呢，这里我觉得可以有两种解决办法，第一种就是清屏后
再把原数组打印出来，第二种就是把光标移动到玩家当前的位置，然后再输出玩家的符号（注意，这里第一种方法开始尝试的时候，由于黑色格子占据
两个字节，所以导致了乱码状况的发生，所以只能采用第二种），那么由于我们采用的边界符号是实心黑色格子，这占据2个字节，所以我们编写了
一个gotoxy函数（网上查的）这个函数可以把光标移动到合适的位置，例如x,y是当前的坐标，那么在图上对应的坐标就是（2*y-2,x-1）这是因为
控制台的x和y方向和你数组打印的方向并不相同，这是需要理清楚的一个数学关系
3.然后就是很简单的思想了，我们采用getch()函数让输入的字符不显示在命令台上，并且我们打印出迷宫和玩家，然后就可以愉快地van♂游戏了
*/
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
using namespace std;
#define row 25
#define col 25
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define START 5
#define END 6
#define wall 7
#define road 8
int map[row + 2][col + 2];
void gotoxy(int x, int y) //移动坐标
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidden()//隐藏光标
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;//赋1为显示，赋0为隐藏
	SetConsoleCursorInfo(hOut, &cci);
}
void init(int x, int y) {
	int c[4][2] = { 0,1,1,0,0,-1,-1,0 };
	for (int i = 0; i < 4; i++) {
		int j = rand() % 4;
			swap(c[i][0], c[j][0]);
		swap(c[i][1], c[j][1]);
	}
	map[x][y] = road;
	for (int i = 0; i < 4; i++) 
		if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == wall) {
			map[x + c[i][0]][y + c[i][1]] = road;
			init(x + 2 * c[i][0], y + 2 * c[i][1]);
		}
}
int get_key() {
	char c;
	while (c = getch()) {
		c = getch();
		if (c == 72)return UP;
		if (c == 80)return DOWN;
		if (c == 75)return LEFT;
		if (c == 77)return RIGHT;
	}
	return 0;
}
void paint(int x, int y) {
	gotoxy(2 * y - 2, x - 1);
	switch (map[x][y]) {
	case END:printf("出"); break;
	case wall:printf("▇"); break;
	case road:printf(" "); break;
	}
}	
void startgame() {
	int x = 2, y = 1;
	int c;
	while (1) {
		gotoxy(2 * y - 2, x - 1);
		printf("●");
		if (map[x][y] == END) {
			system("cls");
				cout << "给个满分吧";
				getch();
				break;
		}
		c = get_key();
		switch (c) {
		case UP: 
			if (map[x - 1][y] != wall)
			{
				paint(x, y);
				x--;
			}
			break;
		case DOWN: 
			if (map[x + 1][y] != wall)
			{
				paint(x, y);
				x++;
			}
			break;
		case LEFT: 
			if (map[x][y - 1] != wall)
			{
				paint(x, y);
				y--;
			}
			break;
		case RIGHT: 
			if (map[x][y + 1] != wall)
			{
				paint(x, y);
				y++;
			}
			break;
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	hidden();
	int i, j;
	for (i = 0; i <= row + 1; i++)
		for (j = 0; j <= col + 1; j++)
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1) //初始化迷宫
				map[i][j] = road;
			else map[i][j] = wall;
	init(2 * (rand() % (row / 2) + 1), 2 * (rand() % (col / 2) + 1));
	for (i = 0; i < row + 1; i++) {
		map[i][0] = wall;
		map[i][col + 1] = wall;
	}
	for (j = 0; j < col + 1; j++) {
		map[0][j] = wall;
		map[col + 1][j] = wall;
	}
	map[row - 1][col] = END;
	for (i = 1; i <= row; i++)
		for (j = 1; j < col+1; j++)
			paint(i, j);
	startgame();
	getch();
	return 0;
}
