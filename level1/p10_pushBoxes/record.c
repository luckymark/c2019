#include"pushbox.h"
#include<stdio.h>
#include<process.h>
#include<windows.h> 
void record(int count,int level)//��¼ÿ�ε����ٲ��� 
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
		MessageBox(0,TEXT("��ϲ������˼�¼"),TEXT("��ϲ"),NULL);
		printf("��ϲ���Ƽ�¼\n"); 
	}
	rewind(fp); 
	for(i=1;i<=Totallevel;i++)
	{
		fprintf(fp,"%d ",i);
		fprintf(fp,"%d ",a[i]);
	}
	printf("���ǵ�%d�أ��㱾�εĲ�����%d\n",level,count);
	printf("���йؿ���ü�¼Ϊ\n");
	for(i=1;i<=Totallevel;i++)
	{
		printf("��%d�� ���ٲ�����%d\n",i,a[i]);
	}
	fclose(fp);
}

