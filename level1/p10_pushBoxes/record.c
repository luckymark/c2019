#include"pushbox.h"
#include<stdio.h>
#include<process.h>
#include<windows.h> 
void record(int count,int level)//记录每次的最少步数 
{
	int i;
	int a[4]={0};
	FILE* fp=fopen("record.txt","r+");
	if(fp==NULL)
	{
		printf("cannot find file\n");
		exit(0);
	}
	for(i=1;i<=Totallevel;i++)
	{
		fscanf(fp,"%d ",&i);
		fscanf(fp,"%d ",&a[i]);
	}
	if(count<a[level])
	{
		a[level]=count;
		MessageBox(0,TEXT("恭喜你打破了记录"),TEXT("恭喜"),NULL);
		printf("恭喜打破纪录\n"); 
	}
	rewind(fp); 
	for(i=1;i<=Totallevel;i++)
	{
		fprintf(fp,"%d ",i);
		fprintf(fp,"%d ",a[i]);
	}
	printf("这是第%d关，你本次的步数是%d\n",level,count);
	printf("所有关卡最好记录为\n");
	for(i=1;i<=Totallevel;i++)
	{
		printf("第%d关 最少步数是%d\n",i,a[i]);
	}
	fclose(fp);
}

