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
		printf("������Ҫ��ʲô��\n");
		printf("1.��ʾ����б�\n");
		printf("2.������Ʒ���\n");
		printf("3.�½���Ʒ����\n");
		printf("4.������Ʒ����\n");
		printf("5.�˳�����\n"); 
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
					printf("��ţ�%d �ͺţ�%s ������%d��\n",i,a[i].model,a[i].number);
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
					printf("��ţ�%d �ͺţ�%s ������%d��\n",i,a[i].model,a[i].number);
			}
			printf("�����������Ʒ��ţ�");
			scanf("%d",&in1);
			printf("\n���������������");
			scanf("%d",&in);
			a[in1].number=a[in1].number+in;
			
			for(int i=0;i<10;i++)
			{
				if(a[i].number!=0)
					printf("��ţ�%d �ͺţ�%s ������%d��\n",i,a[i].model,a[i].number);
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
			printf("������һ��Ҫ�½���������Ʒ�������룺");
			scanf("%d",&new1);
			printf("\n��������Ҫ�½�����Ʒ��\n");
			printf("��ʽ���ͺ� ����\n");
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
			printf("\n���ɹ���\n"); 
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
				printf("��ţ�%d �ͺţ�%s ������%d��\n",i,a[i].model,a[i].number);
			}
			printf("�����������Ʒ��ţ�");
			scanf("%d",&out1);
			printf("\n���������������");
			scanf("%d",&out);
			a[out1].number=a[out1].number-out;
			for(int i=0;i<10;i++)
			{
				if(a[i].number!=0)
					printf("��ţ�%d �ͺţ�%s ������%d��\n",i,a[i].model,a[i].number);
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