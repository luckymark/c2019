#include<stdio.h>
#include<string.h>
#include"warehouse.h"
void xianshi()
{
	int i;
	printf("����б�\n");
	printf("���:�ͺ�\\����\n");
	for(i=1;i<=cnt;i++)
	{
		printf("%d:%s\\%d\n",i,xinghao[i],shuliang[i]);
	}
	printf("��ʾ����\n\n\n");
	return;
}

void ruku()
{
	printf("�����������ͺż�������\n");
	cnt++;
	scanf("%s %d",xinghao[cnt],&shuliang[cnt]);
	printf("���������\n\n\n");
	return;
}

void chuku()
{
	int chukushu;
	printf("��������������ż�������\n");
	int num;
	scanf("%d",&num);
	scanf("%d",&chukushu);
	if(num>cnt)
	{
	   printf("���ﲻ����\n\n\n");
    }
	else if(shuliang[num]>=chukushu)
	{
	   shuliang[num]-=chukushu;
	   printf("�����ѳ���\n\n\n");
    }
	else
	{
	   printf("������������\n\n\n");
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
	printf("������ʾ�ѹر�");
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





















