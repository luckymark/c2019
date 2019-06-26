#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
}node;
void reverse(node *ph)
{
	int c=0;
	node *p=ph,*p2=NULL;
	while(NULL!=p->next)
	{
		c++;
		p=p->next;
		
		printf("第%d个节点的数据为：\n",c,p->num);
	}
	printf("遍历结束");
}
int main(int argc, char *argv[])
{
	struct node *head;
	head=NULL;
	struct node *p1,*p2;
	int i=1;
	p1=(struct node*)malloc(sizeof(struct node));
	p2=p1;
	printf("请输入一个数值，若要结束，请输入-1\n");
	scanf("%d",&p1->num);
	p1->num=i;
	p1->next=NULL;
	
	while(p1->num>0) 
	{
		if(head==NULL)
		{
			head=p1;
		}
		else
		{ 
			p2->next=p1;
			
		}
		p2=p1;
		p1=(struct node*)malloc(sizeof(struct node));
		i=i+1;
		printf("存放地址：%d\n",p2);
		printf("请输入一个数值，若要结束，请输入-1\n");
		scanf("%d",&p1->num); 
	}
	printf("链表输入结束\n");
	reverse(p2);
	free(p1);
	p1=NULL;
	p2->next=NULL;
	return 0;
}