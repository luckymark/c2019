#include<stdio.h>
#include<string.h>
#include"warehouse.h"
void xianshi()
{
	int i;
	printf("存货列表：\n");
	printf("序号:型号\\数量\n");
	for(i=1;i<=cnt;i++)
	{
		printf("%d:%s\\%d\n",i,xinghao[i],shuliang[i]);
	}
	printf("显示结束\n\n\n");
	return;
}

void ruku()
{
	printf("请输入货物的型号及数量：\n");
	cnt++;
	scanf("%s %d",xinghao[cnt],&shuliang[cnt]);
	printf("货物已入库\n\n\n");
	return;
}

void chuku()
{
	int chukushu;
	printf("请输入出库货物序号及数量：\n");
	int num;
	scanf("%d",&num);
	scanf("%d",&chukushu);
	if(num>cnt)
	{
	   printf("货物不存在\n\n\n");
    }
	else if(shuliang[num]>=chukushu)
	{
	   shuliang[num]-=chukushu;
	   printf("货物已出库\n\n\n");
    }
	else
	{
	   printf("货物数量不足\n\n\n");
    }
	return;
}

void tuichu()
{
	cnt2=0;
	int i;
	for(i=1;i<=cnt;i++)
	{
		if(shuliang[i]>0)
		{
			strcpy(xinghao2[i],xinghao[i]);
			shuliang2[i]=shuliang[i];
			cnt2++;
		}
	}
	for(i=1;i<=cnt2;i++)
	{
		strcpy(xinghao[i],xinghao2[i]);
		shuliang[i]=shuliang2[i];
	}
	cnt=cnt2;
	baocun();
	printf("货物显示已关闭");
	return;
}

void duru()
{
	FILE *fin;
	fin = fopen("/tmp/warehouse.txt","r");
	while(1)
	{
		cnt++;
	    fscanf(fin,"%s %d",xinghao[cnt],&shuliang[cnt]);
	    if(shuliang[cnt]==-1)
	    {
			cnt--;
			break;
		}
    }
    fclose(fin);
    return;
}

void baocun()
{
	FILE *fout;
	fout = fopen("/tmp/warehouse.txt","w");
	int i=1;
	while(i<=cnt)
	{
		fprintf(fout,"%s %d\n",xinghao[i],shuliang[i]);
		i++;
	}
	fprintf(fout,"hello -1\n");
	fclose(fout);
	return;
}





















