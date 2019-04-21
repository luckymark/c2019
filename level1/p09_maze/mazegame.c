#include"maze.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y);
void clean(int x,int y);
int get_in();
extern int map[M][M];
void game()
{
	int x=1,y=1;//初始化玩家位置 
	while(1)
	{
		char c;
		gotoxy(y*2,x);
		printf("●");
		if(map[x][y]==END)//判断是否通关 
		{
			MessageBox(0,TEXT("恭喜你通过了关卡"),TEXT("恭喜"),NULL);
			gotoxy(0,M);
			break;
		}
		c=get_in();
		if(c==ESC) //结束游戏 
		{
			gotoxy(0,M);	
			break;
		}
		switch(c)
		{
			case UP:
				
				if(map[x-1][y]!=WALL)
				{
					clean(x,y);
					x--;
				}
				break;
			case DOWN:
				
				if(map[x+1][y]!=WALL)
				{
					clean(x,y);
					x++;	
				}
				break;
			case LEFT:
				
				if(map[x][y-1]!=WALL)
				{
					clean(x,y);
					y--;
				}
				break;
			case RIGHT:
				
				if(map[x][y+1]!=WALL) 
				{
					clean(x,y);
					y++;
				}
				break;
		}
	}
}

void gotoxy(int x,int y) //移动光标到控制台第x行，第y列 
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void clean(int x,int y)//移动光标到原来的位置重新打印覆盖，将原来的玩家位置清除 
{
	gotoxy(y*2,x);
	switch(map[x][y])
	{
		case ROAD:
			printf("  ");
			break;
		case START:
			printf("入");
			break;
		case END:
			printf("出");
			break;	
	}
}
int get_in()//接受键盘的输入
{
	char c;
	while(c=getch()) 
	{
		if(c=='w')  return UP;
		if(c=='a')	return LEFT;
		if(c=='s')	return DOWN;
		if(c=='d')	return RIGHT;
		if(c== 27)	return ESC ;
		else continue;
	}
} 


