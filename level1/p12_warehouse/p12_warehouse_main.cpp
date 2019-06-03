#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct goods
{
	char model[100];
	int number;
}goods;
int main(int argc, char *argv[])
{
	goods a[100];
	int i,j,n,in,out,new1,delete1,in1,out1;
	while(1)
	{
		system("cls");
		printf("请问您要做什么？\n");
		printf("1.显示存货列表\n");
		printf("2.已有商品入库\n");
		printf("3.新建商品种类\n");
		printf("4.已有商品出库\n");
		printf("5.退出程序\n"); 
		scanf("%d",&n);
		system("cls");
		if(n==1)
		{
			FILE *fpRead=fopen("goods.txt","r");
			if(fpRead==NULL)
			{
				return 0;
			}
			for(int i=0;i<10;i++)
			{
				fscanf(fpRead,"%s %d",&a[i].model,&a[i].number);
				if(a[i].number!=0)
					printf("编号：%d 型号：%s 数量：%d个\n",i,a[i].model,a[i].number);
			}
			system("pause");
		}
		if(n==2)
		{
			FILE *fpRead=fopen("goods.txt","r");
			if(fpRead==NULL)
			{
				return 0;
			}
			for(int i=0;i<10;i++)
			{
				fscanf(fpRead,"%s %d",&a[i].model,&a[i].number);
				if(a[i].number!=0)
					printf("编号：%d 型号：%s 数量：%d个\n",i,a[i].model,a[i].number);
			}
			printf("请输入入库商品编号：");
			scanf("%d",&in1);
			printf("\n请输入入库数量：");
			scanf("%d",&in);
			a[in1].number=a[in1].number+in;
			
			for(int i=0;i<10;i++)
			{
				if(a[i].number!=0)
					printf("编号：%d 型号：%s 数量：%d个\n",i,a[i].model,a[i].number);
			}
			FILE *fpWrite=fopen("goods.txt","w");
			if(fpWrite==NULL)
			{  
				return 0;
			}
			for(int i=0;i<10;i++)
				fprintf(fpWrite,"\n%s %d",a[i].model,a[i].number);
			fclose(fpWrite); 
			system("pause");
		}
		if(n==3)
		{
			printf("请问您一共要新建几种新商品？请输入：");
			scanf("%d",&new1);
			printf("\n请输入您要新建的商品：\n");
			printf("格式：型号 数量\n");
			FILE *fpWrite=fopen("goods.txt","a");
			if(fpWrite==NULL)
			{  
				return 0;
			}
			for(int i=0;i<new1;i++)
			{
				scanf("%s %d",&a[i].model,&a[i].number);
				fprintf(fpWrite,"\n%s %d",a[i].model,a[i].number);
			}	
			fclose(fpWrite);
			printf("\n入库成功！\n"); 
			system("pause");
		}
		if(n==4)
		{
			FILE *fpRead=fopen("goods.txt","r");
			if(fpRead==NULL)
			{
				return 0;
			}
			for(int i=0;i<10;i++)
			{
				fscanf(fpRead,"%s %d",&a[i].model,&a[i].number);
				printf("编号：%d 型号：%s 数量：%d个\n",i,a[i].model,a[i].number);
			}
			printf("请输入出库商品编号：");
			scanf("%d",&out1);
			printf("\n请输入出库数量：");
			scanf("%d",&out);
			a[out1].number=a[out1].number-out;
			for(int i=0;i<10;i++)
			{
				if(a[i].number!=0)
					printf("编号：%d 型号：%s 数量：%d个\n",i,a[i].model,a[i].number);
			}
			FILE *fpWrite=fopen("goods.txt","w");
			if(fpWrite==NULL)
			{  
				return 0;
			}
			for(int i=0;i<10;i++)
				fprintf(fpWrite,"\n%s %d",a[i].model,a[i].number);
			fclose(fpWrite); 
			system("pause");
		}
		if(n==5)
			exit(0);
	}
	
	return 0;
}