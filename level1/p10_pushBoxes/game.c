#include"pushbox.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void clean(int x,int y);
int get_in();
int count=0;
void game()
{
	int x=1,y=1;//初始化玩家位置
	while(1)
	{
		char c;
		gotoxy(y*2,x);
		printf("●");
		if(flag==0)//判断是否通关 
		{
			MessageBox(NULL,TEXT("恭喜通过此关"),TEXT("恭喜"),MB_OK);
			gotoxy(0,M+3);
			record(count,level);
			break;
		}
		c=get_in();//接收键盘输入 
		if(c==ESC) //中止游戏 
		{
			gotoxy(0,M+3);	
			break;
		}
		switch(c)
		{
			case UP:
				count++;
				if((map[level][x-1][y]==ROAD)||(map[level][x-1][y]==DESTINATION))
				{
					clean(x,y);
					x--;
				}
				else if((map[level][x-1][y]==BOX)&&(map[level][x-2][y]==ROAD))
				{
					map[level][x-1][y]=ROAD;
					map[level][x-2][y]=BOX;
					gotoxy(y*2,x-2);
					printf("⊙");
					clean(x,y);
					x--;
				}
				else if((map[level][x-1][y]==BOX)&&(map[level][x-2][y]==DESTINATION)) 
				{
					map[level][x-1][y]=ROAD;
					map[level][x-2][y]=CORRECT;
					gotoxy(y*2,x-2);
					printf("⊙");
					clean(x,y);
					flag--;
					x--;
				}
				else if((map[level][x-1][y]==CORRECT)&&(map[level][x-2][y]==ROAD))//将已归位的箱子推出目标 
				{
					map[level][x-1][y]=DESTINATION;
					map[level][x-2][y]=BOX;
					gotoxy(y*2,x-2);
					printf("⊙");
					clean(x,y);
					flag++;
					x--;
				}
				break;
			case DOWN:
				count++;
				if((map[level][x+1][y]==ROAD)||(map[level][x+1][y]==DESTINATION))
				{
					clean(x,y);
					x++;
				}
				else if((map[level][x+1][y]==BOX)&&(map[level][x+2][y]==ROAD))
				{
					map[level][x+1][y]=ROAD;
					map[level][x+2][y]=BOX;
					gotoxy(y*2,x+2);
					printf("⊙");
					clean(x,y);
					x++;
				}
				else if((map[level][x+1][y]==BOX)&&(map[level][x+2][y]==DESTINATION))
				{
					map[level][x+1][y]=ROAD;
					map[level][x+2][y]=CORRECT;
					gotoxy(y*2,x+2);
					printf("⊙");
					clean(x,y);
					flag--;
					x++;
				}
				else if((map[level][x+1][y]==CORRECT)&&(map[level][x+2][y]==ROAD))
				{
					map[level][x+1][y]=DESTINATION;
					map[level][x+2][y]=BOX;
					gotoxy(y*2,x+2);
					printf("⊙");
					clean(x,y);
					flag++;
					x++;
				}
				break;
			case LEFT:
				count++;
				if((map[level][x][y-1]==ROAD)||(map[level][x][y-1]==DESTINATION))
				{
					clean(x,y);
					y--;
				}
				else if((map[level][x][y-1]==BOX)&&(map[level][x][y-2]==ROAD))
				{
					map[level][x][y-1]=ROAD;
					map[level][x][y-2]=BOX;
					gotoxy(y*2-4,x);
					printf("⊙");
					clean(x,y);
					y--;
				}
				else if((map[level][x][y-1]==BOX)&&(map[level][x][y-2]==DESTINATION))
				{
					map[level][x][y-1]=ROAD;
					map[level][x][y-2]=CORRECT;
					gotoxy(y*2-4,x);
					printf("⊙");
					clean(x,y);
					flag--;
					y--;
				}
				else if((map[level][x][y-1]==CORRECT)&&(map[level][x][y-2]==ROAD))
				{
					map[level][x][y-1]=DESTINATION;
					map[level][x][y-2]=BOX;
					gotoxy(y*2-4,x);
					printf("⊙");
					clean(x,y);
					flag++;
					y--;
				}
				break;
			case RIGHT:
				count++;	
				if((map[level][x][y+1]==ROAD)||(map[level][x][y+1]==DESTINATION))
				{
					clean(x,y);
					y++;
				}
				else if((map[level][x][y+1]==BOX)&&(map[level][x][y+2]==ROAD))
				{
					map[level][x][y+1]=ROAD;
					map[level][x][y+2]=BOX;
					gotoxy(y*2+4,x);
					printf("⊙");
					clean(x,y);
					y++;
				}
				else if((map[level][x][y+1]==BOX)&&(map[level][x][y+2]==DESTINATION))
				{
					map[level][x][y+1]=ROAD;
					map[level][x][y+2]=CORRECT;
					gotoxy(y*2+4,x);
					printf("⊙");
					clean(x,y);
					flag--;
					y++;
				}
				else if((map[level][x][y+1]==CORRECT)&&(map[level][x][y+2]==ROAD))
				{
					map[level][x][y+1]=DESTINATION;
					map[level][x][y+2]=BOX;
					gotoxy(y*2+4,x);
					printf("⊙");
					clean(x,y);
					flag++;
					y++;
				}
				break;
		}
	}
}
void clean(int x,int y)//移动光标到原来的位置重新打印覆盖，将原来的玩家位置清除 
{
	gotoxy(y*2,x);
	switch(map[level][x][y])
	{
		case ROAD:
			printf("  ");
			break;
		case DESTINATION:
			printf("☆");
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


