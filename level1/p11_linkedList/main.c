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
	struct Node * pHead=NULL;//����ͷָ��,�����������
    int len;
    printf("��������Ҫ���ɵ����ӽڵ�ĸ�����len=");
	scanf("%d",&len);
	pHead=CreateList(len);
	TraverseList(pHead);
	printf("\n�����:\n");
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
		printf("����ʧ�ܣ�������ֹ!\n");
		exit(-1);
	}
	struct Node * pTail=pHead;
	pTail->pNext=NULL;


	for(i=0;i<len;++i)
	{
		printf("�������%d���ڵ��ֵ��",i+1);
		scanf("%d",&val);

		struct Node * pNew=(struct Node *)malloc(sizeof(struct Node));
		if(NULL==pNew)
		{
			printf("����ʧ��,������ֹ!\n");
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
		printf("����Ϊ�գ�");
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
		printf("����Ϊ�գ�");
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
          printf("ֵΪ5�Ľڵ�����ǣ�%d ",index);
          break;
      }
      index++;
   }
}





