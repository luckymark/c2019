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
void printmap(void)//��ӡ�Թ���ͼ 
{	
	int i=0,j=0;
	flag=0;
	hidden();
	FILE* fp=fopen("map.txt","r");//��ȡmap.txt�ļ� 
	if(fp==NULL)
	{
		printf("���ļ�");
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
	printf("����������еĹؿ�,����1��2��3��,����󰴻س�����\n");
	while(1)
	{
		scanf("%d",&level);
		getchar();
		if((level==1)||(level==2)||(level==3)) break;
		else
		{
			printf("�������룬����������ؿ�\n");
		}	
	}
	gotoxy(0,0);
	for(i=0;i<M;i++)//��ӡ��Ϸ��ͼ 
	{
		for(j=0;j<M;j++)
		{
			if	(map[level][i][j]==WALL)
				{
					printf("�~");
				}
			else if(map[level][i][j]==ROAD)
				{
					printf("  ");
				}
			else if(map[level][i][j]==BOX)
				{
					printf("��");
				}
			else if(map[level][i][j]==DESTINATION)
				{
					printf("��");
					flag++;
				}
		}
		printf("\n");
	} 
	printf("��Ϸ˵������wasd���������ƶ�����Esc���˳���Ϸ\n");
	printf("          �Ѵ�����Ҫ�ƶ���Բ�����ӣ�������Բ�����������������Ϸʤ��\n");
}
void hidden(void)//���ع��
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
    SetConsoleCursorInfo(hOut,&cci);
}

