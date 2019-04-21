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
	int x=1,y=1;//��ʼ�����λ�� 
	while(1)
	{
		char c;
		gotoxy(y*2,x);
		printf("��");
		if(map[x][y]==END)//�ж��Ƿ�ͨ�� 
		{
			MessageBox(0,TEXT("��ϲ��ͨ���˹ؿ�"),TEXT("��ϲ"),NULL);
			gotoxy(0,M);
			break;
		}
		c=get_in();
		if(c==ESC) //������Ϸ 
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

void gotoxy(int x,int y) //�ƶ���굽����̨��x�У���y�� 
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void clean(int x,int y)//�ƶ���굽ԭ����λ�����´�ӡ���ǣ���ԭ�������λ����� 
{
	gotoxy(y*2,x);
	switch(map[x][y])
	{
		case ROAD:
			printf("  ");
			break;
		case START:
			printf("��");
			break;
		case END:
			printf("��");
			break;	
	}
}
int get_in()//���ܼ��̵�����
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


