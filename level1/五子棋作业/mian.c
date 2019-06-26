#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
int main(int argc, char *argv[])
{
	int i,j,n,s,line,column;
	int liner,columnr;
	char columnc,key,linec;
	char *a[100];
	n=0;
	for(i=0;i<30;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*100);
	}
	createmap(a);
	while(1)
	{
		printf("人工智障版五子棋 BY 孙*竣 \n");
		printmap(a);
		check_5(a);
		printf("输入格式，输入坐标即可，如：A 1(注意字母与数字之间的空格)\n");
		printf("请输入"); 
		point1:scanf("%s %d",&columnc,&line);
		line=line*2-1;
		column=((int)columnc-64)*2-2;
		if((a[line][column]=='X')||(a[line][column]=='O'))
		{
	 		printf("这个位置已经被下过了\n");
	 		goto point1;	
		}
		if(column>=0)a[line][column]='X';//如果不对column进行判断，column每次都会先=-110，然后才是正确的坐标，很迷的BUG 
		printf("\n");
		deal_live_3(a);
		system("cls");
	}
	return 0;
}
/*随机乱下版的残骸： 
	time_t t1,t2;
	point2:srand((unsigned) time(0));
           columnr=(rand()%14+1)*2;
           liner=(rand()%15+1)*2-3;
		   if((a[liner][columnr]=='X')||(a[liner][columnr]=='O'))goto point2;
		   if(columnr>=0)a[liner][columnr]='O';
*/ 