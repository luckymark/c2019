#include"pushbox.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<process.h>
#include<stdlib.h>
void hidden(void);
int map[Totallevel+1][M][M]={0};
int level;
int flag; 
void printmap(void)//打印迷宫地图 
{	
	int i=0,j=0;
	flag=0;
	hidden();
	FILE* fp=fopen("map.txt","r");//读取map.txt文件 
	if(fp==NULL)
	{
		printf("无文件");
		exit(0);
	}
	for(level=1;level<=Totallevel;level++)
	{
		for(i=0;i<M;i++)
		{
			for(j=0;j<M;j++)
			{
				fscanf(fp,"%d",&map[level][i][j]);
			}
			fscanf(fp,"\n");
		}
		fscanf(fp,"\n\n");
	}
	fclose(fp);
	printf("输入你想进行的关卡,共有1，2，3关,输入后按回车结束\n");
	while(1)
	{
		scanf("%d",&level);
		getchar();
		if((level==1)||(level==2)||(level==3)) break;
		else
		{
			printf("错误输入，请重新输入关卡\n");
		}	
	}
	gotoxy(0,0);
	for(i=0;i<M;i++)//打印游戏地图 
	{
		for(j=0;j<M;j++)
		{
			if	(map[level][i][j]==WALL)
				{
					printf("▇");
				}
			else if(map[level][i][j]==ROAD)
				{
					printf("  ");
				}
			else if(map[level][i][j]==BOX)
				{
					printf("⊙");
				}
			else if(map[level][i][j]==DESTINATION)
				{
					printf("☆");
					flag++;
				}
		}
		printf("\n");
	} 
	printf("游戏说明：用wasd控制人物移动，按Esc键退出游戏\n");
	printf("          ⊙代表需要移动的圆形箱子，将所有圆形箱子推至☆处即可游戏胜利\n");
}
void hidden(void)//隐藏光标
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//赋1为显示，赋0为隐藏
    SetConsoleCursorInfo(hOut,&cci);
}

