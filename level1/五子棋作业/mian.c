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
		printf("�˹����ϰ������� BY ��*�� \n");
		printmap(a);
		check_5(a);
		printf("�����ʽ���������꼴�ɣ��磺A 1(ע����ĸ������֮��Ŀո�)\n");
		printf("������"); 
		point1:scanf("%s %d",&columnc,&line);
		line=line*2-1;
		column=((int)columnc-64)*2-2;
		if((a[line][column]=='X')||(a[line][column]=='O'))
		{
	 		printf("���λ���Ѿ����¹���\n");
	 		goto point1;	
		}
		if(column>=0)a[line][column]='X';//�������column�����жϣ�columnÿ�ζ�����=-110��Ȼ�������ȷ�����꣬���Ե�BUG 
		printf("\n");
		deal_live_3(a);
		system("cls");
	}
	return 0;
}
/*������°�Ĳк��� 
	time_t t1,t2;
	point2:srand((unsigned) time(0));
           columnr=(rand()%14+1)*2;
           liner=(rand()%15+1)*2-3;
		   if((a[liner][columnr]=='X')||(a[liner][columnr]=='O'))goto point2;
		   if(columnr>=0)a[liner][columnr]='O';
*/ 