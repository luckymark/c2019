#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
void start();
void output();
void input();
void change();
void dele();
void search();
void insert();
struct  GOODS
{
  char goods_id[30];
  char goods_name[30];
  char goods_price[20];
  char goods_discount[20];
  int goods_amount;
  int goods_remain;
};
struct  GOODS goods[MAX],goodsinsert[MAX],G[MAX];
int count=0;
int main()
{
    while(1)
    start();
 }
void start()
{
int ch;
printf("\n\t\t\t\t超市商品信息管理系统\n");
printf("\t\t\t****************************\n");
printf("\t\t\t1.商品的录入\n");
printf("\t\t\t2.修改某个商品的信息\n");
printf("\t\t\t3.删除某个商品的信息\n");
printf("\t\t\t4.查找某个商品的信息\n");
printf("\t\t\t5.插入某个商品的信息\n");
printf("\t\t\t6.退出系统\n");
printf("\t\t\t****************************\n");
printf("\n\n输入你的选择（1-6）:");
scanf("%d",&ch);
    switch(ch)
        {
        case 1:
		{
		 input();
         break;}
        case 2:	
		{	
		 change();
		 break;
		}
		case 3:
		{
		 dele();
		 break;
		}
        case 4:
		{
		 search();
		 break; 
		 }
		case 5:
		{
		 insert();
  		 break;
		}
 		default :
		{
		 printf("\n退出系统并按任意键退出系统");
  		 exit(EXIT_SUCCESS);
		}
        }


}


void input()
{


   char flag[20];
   do
   	{
   		printf("请输入你的商品信息:\n");
   		printf("商品编号:");
   		scanf("%s",goods[count].goods_id);
   		printf("商品名字:");
   		scanf("%s",goods[count].goods_name);
   		printf("商品价格:");
   		scanf("%s",goods[count].goods_price);
   		printf("商品折扣:");
  		scanf("%s",goods[count].goods_discount);
   		printf("商品总数目:");
   		scanf("%d",&goods[count].goods_amount);
   		printf("商品剩余数目:");
   		scanf("%d",&goods[count].goods_remain);
   		count++;
   		printf("是否继续输入数据 y是  n否 : ");
   		scanf("%s",flag);
   	}while(strcmp(flag,"y")==0||strcmp(flag,"Y")==0);
    output();
}
void change()
{
    char ch[20],a[20];
	int i,t,m=0;
    printf("\n是否根据商品的编号进行修改 (y/n): ");
    scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)
    { 
	 	printf("\n输入商品的编号:");
     	scanf("%s",a);
     	for(i=0;i<count;i++)
   	{
   		if(strcmp(goods[i].goods_id,a)==0)
		{ 
	 		m++;
	 		t=i;
		}
	}
	if(m==0)
	{
		printf("\n对不起，你输入的商品不存在。请检查！！！\n");
	}
	else if(m==1)
	{
		printf("\n\n是否改变商品的名字(y/n):");
		scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)   
	{ 
		printf("\n商品的名字:"); scanf("%s",goods[t].goods_name);
	}
    printf("\n是否改变商品的价格(y/n): ");
	scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)   
	{
		printf("\n商品的价格:"); 
		scanf("%s",goods[t].goods_price);}
    	printf("\n是否改变商品的折扣(y/n): ");
    	scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)  
	{
		printf("\n商品的折扣:"); 
		scanf("%s",goods[t].goods_discount);
	}
    	printf("\n是否改变商品的数量(y/n): ");
    	scanf("%s",ch);
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)  
	{
		printf("\n商品的数量:"); 
		scanf("%d",&goods[t].goods_amount);
	}
		printf("\n是否改变商品的剩余数目(y/n): ");
    	scanf("%s",ch);
	if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0)   
	{
	 	printf("\n商品的剩余数目"); 
		scanf("%d",&goods[t].goods_remain);
	}
		output();
	}
    else 
	{
		printf("\n商品的编号错误，不能重复编号。请选择删除商品！！！\n");
    }
	} 
    else 
   printf("\n*********请继续选择**********\n");
}
void output()
{
   int i;
   for(i=0;i<count;i++)
   {
        printf("\n商品编号:%s商品名字:%s商品价格:%s商品折扣:%s商品数目:%d商品剩余数目:%d",
        goods[i].goods_id,goods[i].goods_name,goods[i].goods_price,goods[i].goods_discount,
        goods[i].goods_amount,goods[i].goods_remain);
	}
}
void dele()
{
   int i,j,t,m=0;
   char c[20];
   printf("\n输入商品的编号来删除商品:");
   scanf("%s",c);
   for(i=0;i<count;i++)
   {
   		if(strcmp(c,goods[i].goods_id)==0)
        {
		 	m++;
			t=i;
		}
   }
   if(m==0)
   printf("对不起，你输入的商品没找到。请检查！！！\n");
   else
   {
   		printf("********删除的商品是*********\n:");
		printf("商品编号:%s商品名字:%s商品价格:%s商品折扣:%s商品数目:%d商品剩余数目:%d",
		goods[t].goods_id,goods[t].goods_name,goods[t].goods_price,goods[t].goods_discount,
		goods[t].goods_amount,goods[t].goods_remain);
  		for(j=t;j<count-1;j++)
    	goods[j]=goods[j+1];
		count--;
    	printf("\n\t\t\t*********请检查是否删除正确********\n");
   	 	output();
	}
}


void search()
{
	int i,t=0,b,j,number,m=0;
	char a[20],num[20];
    printf("\n1.按商品的名字来查找选1:");
    printf("\n2.按商品的折扣来查找选2:");
    printf("\n3.按商品的价格来查找选3:\n");
    scanf("%d",&b);
    switch(b)
   {
   		 case 1:
		{ 
		printf("\n请输入商品的名字:");
   		scanf("%s",a);
        for(i=0;i<count;i++)
        {
   			if(strcmp(goods[i].goods_name,a)==0)
 			{
		 		m++;
				num[t++]=i;
			}
   		}
   		if(m==0)
   			printf("对不起，你输入的商品不在其范围里。请检查！！！\n");
   		else  for(j=0;j<t;j++)
		{  
			number=num[j];
   			printf("************已查到商品信息****************\n");
			printf("商品编号:%s商品名字:%s商品价格:%s商品折扣:%s商品数目:%d商品剩余数目:%d\n\n",
			goods[number].goods_id,goods[number].goods_name,goods[number].goods_price,
			goods[number].goods_discount,goods[number].goods_amount,goods[number].goods_remain);}break;}
   		case 2:
			{
				printf("\n请输入商品的折扣:");
   				scanf("%s",a);
   				for(i=0;i<count;i++)
   				{
				   if(strcmp(goods[i].goods_discount,a)==0)
				    {
				   		m++;num[t++]=i;
					}
   				}
				   if(m==0)printf("对不起，你输入的商品不在其范围里。请检查！！！\n");
				   else  
				   for(j=0;j<t;j++)
				   {
				    number=num[j];
   					printf("************已查到商品信息****************\n");
					printf("商品编号:%s商品名字:%s商品价格:%s商品折扣:%s商品数目:%d商品剩余数目:%d\n\n",
					goods[number].goods_id,goods[number].goods_name,goods[number].goods_price,
					goods[number].goods_discount,goods[number].goods_amount,goods[number].goods_remain);
				   }
				   break;
			}
		case 3:
		    {
		   		printf("\n请输入商品的价格:");
   				scanf("%s",a);
   				for(i=0;i<count;i++)
				    {
				   		if(strcmp(goods[i].goods_price,a)==0)
						    {
						   		m++;num[t++]=i;
							}
   					}
					   if(m==0)printf("对不起，你输入的商品不在其范围里。请检查！！！\n");
					   else  
					   for(j=0;j<t;j++)
					    {
					    	number=num[j];
							printf("************已查到商品信息****************\n");
							printf("商品编号:%s商品名字:%s商品价格:%s商品折扣:%s商品数目:%d商品剩余数目:%d\n\n",
							goods[number].goods_id,goods[number].goods_name,goods[number].goods_price,
							goods[number].goods_discount,goods[number].goods_amount,goods[number].goods_remain);
						}
						break;
			}
   }
}
void  insert()
{
	int i,j,m,n;
	printf("\n你想要插入的位置:");
	scanf("%d",&i);count++;
	printf("\n输入要插入的商品编号:");scanf("%s",goodsinsert[i-1].goods_id);
	printf("\n输入要插入的商品名字:");scanf("%s",goodsinsert[i-1].goods_name);
	printf("\n输入要插入的商品价格:");scanf("%s",goodsinsert[i-1].goods_price);
	printf("\n输入要插入的商品折扣:");scanf("%s",goodsinsert[i-1].goods_discount);
	printf("\n输入要插入的商品数目:");scanf("%d",&goodsinsert[i-1].goods_amount);
	printf("\n输入要插入的商品剩余数目:");scanf("%d",&goodsinsert[i-1].goods_remain);
	for(j=0;j<i-1;j++)
	G[j]=goods[j];
	G[j]=goodsinsert[i-1];
	for(m=j+1;m<count;m++)
	G[m]=goods[m-1];
	for(n=0;n<count;n++)
	goods[n]=G[n];
	printf("\n\t\t\t*********请检查是否插入正确********\n");
  	output();
} 

