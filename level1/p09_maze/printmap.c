#include"maze.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void hidden(void);
int map[M][M]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,1,1,1,1,1,1,0,1,0,1,1,1,1,0},
	{0,1,0,1,1,0,0,1,0,1,0,1,0,0,1,0},
	{0,1,0,0,1,1,1,1,0,1,0,1,1,1,1,0},
	{0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0},
	{0,1,0,1,1,1,1,0,0,1,0,1,0,0,0,0},
	{0,1,0,1,0,0,1,1,1,0,0,1,1,1,1,0},
	{0,1,1,1,1,1,0,1,0,1,0,1,0,0,1,0},
	{0,0,1,0,0,1,0,1,0,1,1,1,1,0,1,0},
	{0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,0},
	{0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0},
	{0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0},
	{0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0}
 };

void printmap(void)//打印迷宫地图 
{	
	hidden();
	int i=0,j=0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			if(map[i][j]==WALL)
				printf("▇");
			else if(map[i][j]==ROAD)
				printf("  ");
			else if(map[i][j]==START)
				printf("入");
			else if(map[i][j]==END)
				printf("出");			
		}
		printf("\n");
	} 
	printf("游戏说明：用wasd控制人物移动，按Esc键退出游戏");
}
void hidden()//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//赋1为显示，赋0为隐藏
    SetConsoleCursorInfo(hOut,&cci);
}

