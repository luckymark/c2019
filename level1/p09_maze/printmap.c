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

void printmap(void)//��ӡ�Թ���ͼ 
{	
	hidden();
	int i=0,j=0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			if(map[i][j]==WALL)
				printf("�~");
			else if(map[i][j]==ROAD)
				printf("  ");
			else if(map[i][j]==START)
				printf("��");
			else if(map[i][j]==END)
				printf("��");			
		}
		printf("\n");
	} 
	printf("��Ϸ˵������wasd���������ƶ�����Esc���˳���Ϸ");
}
void hidden()//���ع��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
    SetConsoleCursorInfo(hOut,&cci);
}

