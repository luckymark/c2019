#include<stdio.h>
#include<stdlib.h>
int cnt=0;
struct node{
	int value;
	struct node *p;
};
struct node *head,*tail;
void add();
void creat();
void showvalue();
void negate();
int find(int l,int r);
int main()
{
	int i;
	creat();
	for(i=1;i<10;i++)add();//创建
	showvalue();//遍历
	printf("\n");
	negate();//反序
	showvalue();//显示反序值
	printf("\n");
	int ans=find(0,cnt);//查找
	printf("%d\n",ans);
	int ans2=find(ans+1,cnt);
	printf("%d",ans2);
	return 0;
}
void creat()
{
	head=(struct node*)malloc(sizeof(struct node));
	head->value=cnt;cnt++;
	head->p=NULL;
	tail=head;
	return;
}
void add()
{
	struct node *newone;
	newone=(struct node*)malloc(sizeof(struct node));
	newone->value=cnt;cnt++;
	newone->p =NULL;
	tail->p =newone;
	tail=newone;
	return;
}
void showvalue()
{
	int i;
	struct node *newone=head;
	for(i=0;i<cnt;i++)
	{
		printf("%d",newone->value);
		newone=newone->p ;
	}
	return;
}
void negate()
{
	struct node *newone=NULL,*newtwo=head,*newthree;
	int i=0;
	while(i<cnt)
	{
		newthree=newtwo->p ;
		newtwo->p =newone;
		newone=newtwo;
		newtwo=newthree;
		i++;
    }
	newthree=head;
	head=tail;
	tail=newthree;
	return;
}
int find(int l,int r)
{
	if(l>r)return -1;
	int i;
	struct node *newone=head;
	for(i=0;i<l;i++)
	{
		newone=newone->p ;
	}
	int ans=-1;
	for(i=l;i<r;i++)
	{
		if(newone->value ==5)
		{
			ans=i;
			break;
		}
		newone=newone->p ;
	}
	return ans;
}



