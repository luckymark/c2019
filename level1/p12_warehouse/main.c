#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#define M 50
/*ʵ�����µĲ˵���������ѡ��˵����ܣ���
��ʾ����б�
���
����
�˳�����
ʵ�ֲ˵���Ӧ���ܣ����¼������ͺš���������Ϣ����
��������ʱ���ļ��ж�ȡ��ǰ������ݣ��˳�ʱ���������ݣ�
*/
typedef struct
{
	int num;			//��Ʒ���
	char name[20];		//��Ʒ����
	int stock;			//ԭʼ���
	int in;				//�����Ŀ
	int out;			//������Ŀ
	int amount;			//���տ��
	int warning_value;
	int state;			//���״̬
}goods;
goods s[M];				//���ڴ�Ż�Ʒ��Ϣ
goods r[M];				//���ڴ������Ʒ��Ϣ
goods t[M];				//���ڴ�ų����Ʒ��Ϣ

void Re_file();
void Stock_in();
void Stock_out();
void Display();
void Printf_back();
void Modify();
void Statistics();
int Wr_file();

int N;
int P;

int main()
{
	int sele;
	Re_file();    //��ȡ��Ʒ��Ϣ
	sele=1;
	while(sele)
	{
		system("cls");
		printf("\n\n");
		printf("*********************************************\n");
		printf("*                                           *\n");
		printf("*       1.���              2.����          *\n");
		printf("*                                           *\n");
		printf("*                                           *\n");
		printf("*       3.���              4.�˳�          *\n");
		printf("*                                           *\n");
		printf("*********************************************\n");
		printf("��ѡ�������:");
		scanf("%d",&sele);
		switch(sele)
		{
			case 1:Stock_in();Display();break;
			case 2:Stock_out();Display();break;
			case 3:Statistics();break;
			case 4:exit(0);sele=0;break;
		}
		printf("\n\n�����������...\n");
		getch();
	}
	Wr_file();
	return 0;
}

void Re_file()		//����ԭʼ����ļ�
{
	FILE*fp;
	N=0;
	fp=fopen("goods.txt","r");
	while(fscanf(fp,"%d%s%d%d%d%d%d",&s[N].num,&s[N].name,&s[N].stock,&s[N].in,&s[N].out,&s[N].amount,&s[N].warning_value)!=EOF)N++;
	fclose(fp);
	P=N;
}

void Stock_in()		//��������ļ�
{
	FILE*fp;
	int i,j;
	N=0;
	fp=fopen("stockin.txt","r");
	while(fscanf(fp,"%d%d",&r[N].num,&r[N].in)!=EOF)N++;
	fclose(fp);
	for(i=0;i<P;i++)
	{
		for(j=0;j<N;j++)
		{
			if(r[i].num==s[j].num)
				s[j].in=r[j].in;
		}
	}
	for(i=0;i<P;i++)
	s[i].amount=s[i].stock+s[i].in;
}
void Stock_out()	//��������ļ�
{
	FILE*fp;
	int i,j;
	N=0;
	fp=fopen("stockout.txt","r");
	while(fscanf(fp,"%d%d",&t[N].num,&t[N].out)!=EOF)N++;
	fclose(fp);
	for(i=0;i<P;i++)
	{
		for(j=0;j<N;j++)
		{
			if(t[i].num==s[j].num)
				s[j].out=t[j].out;
		}
	}
	for(i=0;i<P;i++)
	s[i].amount=s[i].stock+s[i].in-s[i].out;
}

void Display()		//��ʾ������
{
	int i,j;
	system("cls");
	//Estimate();
	printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  \n");
	for(i=0,j=1;i<P;i++,j++)
	{
		if(s[i].state==0)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
			printf("%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
			if(j%10==0&&j<P)
			{
				HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf("�����������...");
				getch();
				puts("\n");
				printf("��Ʒ���  ��Ʒ����  ԭʼ���  �����Ŀ  ������Ŀ  ���տ��  \n");
			}
		}
	}
}

void Printf_back()     //�������˵�
{
	getch();
	main();
}

void Statistics()       //ͳ����Ŀ
{
	int k,i,j,m=0,n=0;
	system("cls");
	printf("\n\n");
	printf("*********************************************\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*      1.�������         2.���״̬        *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");
	printf("\n\n�������ѯѡ��:");
	scanf("%d",&k);
	if(k==1)
	{
		for(i=0;i<P;i++)
			m=m+s[i].amount;
		printf("�������Ϊ��%d",m);
	}

	Wr_file();
}

int Wr_file()       //д����ļ�
{
	FILE*fp;
	int i;
	fp=fopen("amount.txt","w");
	for(i=0;i<P;i++)
		fprintf(fp,"%-9d  %-10s%-10d%-10d%-10d%-10d%-10d\n",s[i].num,s[i].name,s[i].stock,s[i].in,s[i].out,s[i].amount,s[i].warning_value);
	fclose(fp);
	return 1;
}
