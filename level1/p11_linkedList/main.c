#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node * pNext;
};
struct Node * CreateList(int len);
void TraverseList(struct Node * pHead);
void conTraverseList(struct Node * pHead,int len);
int find5(struct Node * pHead,int len);
int main(void)
{
	struct Node * pHead=NULL;//定义头指针,用来存放链表
    int len;
    printf("请输入需要生成的链接节点的个数：len=");
	scanf("%d",&len);
	pHead=CreateList(len);
	TraverseList(pHead);
	printf("\n逆序后:\n");
    conTraverseList(pHead,len);
    find5(pHead,len);
	return 0;
}
struct Node * CreateList(int len)
{
	int i;
	int val;
	struct Node * pHead=(struct Node *)malloc(sizeof(struct Node));
	if(NULL==pHead)
	{
		printf("分配失败，程序终止!\n");
		exit(-1);
	}
	struct Node * pTail=pHead;
	pTail->pNext=NULL;


	for(i=0;i<len;++i)
	{
		printf("请输入第%d个节点的值：",i+1);
		scanf("%d",&val);

		struct Node * pNew=(struct Node *)malloc(sizeof(struct Node));
		if(NULL==pNew)
		{
			printf("分配失败,程序终止!\n");
			exit(-1);
		}
		pNew->data=val;
		pTail->pNext=pNew;
		pNew->pNext=NULL;
		pTail=pNew;
	}
	return pHead;
}

void TraverseList(struct Node * pHead)
{
	struct Node * p=pHead->pNext;
	if(pHead->pNext==NULL)
	{
		printf("链表为空！");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->pNext;
		}
	}
}
void conTraverseList(struct Node * pHead,int len)
{
	struct Node * p=pHead->pNext;
	int j,i=0;;
	if(pHead->pNext==NULL)
	{
		printf("链表为空！");
	}
	else
	{
		for(i=0;i<len;i++)
        {
            p=pHead;
            for(j=0;j<len;j++)
            {
                 p=p->pNext;
                if(j=len-i-1)
                {
                    printf("%d ",p->data);
                    break;
                }


            }
        }
	}
}
int find5(struct Node * pHead,int len)
{
   int index=1;
   struct Node * p=pHead->pNext;
   for(int i=0;i<len;i++)
   {
      if(p->data==5)
      {
          printf("值为5的节点序号是：%d ",index);
          break;
      }
      index++;
   }
}





