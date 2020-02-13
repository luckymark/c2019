typedef struct List
{
	int value;//������
	struct List * pNext;//ָ������ΪҪָ����һ����㣬�������pNextָ������� List * ���͵�
}NODE,* PNODE;

PNODE create(void) 
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//�ȸ��׽�����ռ�,�������Ч����

	
	int i,len,val;//len:��Ҫ������������Ч�����,val:��ʱ����û�����ĵ�ǰ����ֵ
	PNODE pTail = pHead;//pTail�Ĺ��ܼ�����
	pHead->pNext=NULL;
	pTail->pNext = NULL;

	if (pHead == NULL)//����ʧ��
	{
		printf("Failed to allocate,program stop soon!");
		exit(-1);
	}
	
	
	printf("input how many values:\n");
	scanf("%d", &len);//��ȡ��Ҫ������������Ч���������Ϊͷ���һ�㲻��Ϊ����Ч��㣩
	if(len>=0)
	{
	  for (i = 0; i < len; i++)
		{
			printf("Input NO.%d value:",i + 1);//���ݽṹһ���������ϰ�ߣ�����������һ���±�-1
			scanf("%d", &val);//��û�з���ռ����ǰ���ݣ���ʱ�����val��

			PNODE pNew= (PNODE)malloc(sizeof(NODE));//��������ݷ���ռ�,��pNew��ʾ����¿ռ�ĵ�ַ
			if (pNew== NULL)//����ʧ��
			{
				printf("Failed to allocate,program stop soon!");
				exit(-1);
			}
			pNew->value = val;//��val��ֵ����������
			pTail->pNext = pNew;//�����д����pHead->pNext = pNew;�������н�㶼����pHead�� 
			                 //���´����Ľ��ҵ�ԭ��������һ�����ĺ��棬������һ��ָ��pTailʱ��ָ��β��㣬��ôֻ��pTail->pNext=pNew����
			pNew->pNext = NULL;//��ʱ�½�������һ����㣬ָ��NULL
			pTail = pNew;//�ٴν�pTail�ƶ���ָ�����һ�����
		}
	}
	else
	{
		printf("Error!");
	}

	return pHead;//����ֵΪ�׽��ĵ�ַ�������ͱ��ڶ�������в���
}

void print_all(PNODE pHead)//�����������
{
	PNODE p=pHead->pNext;//��pָ��ͷ��� 
	
	while(p!=NULL)//û��ָ�����һ�����/������ֻ��ͷ��� 
	{
		printf("%d ",p->value);
		p=p->pNext;//��λ 
	}
	printf("\n");//�������� 
	
	return;
}

void find_value(PNODE pHead,int val,int num)
{
	PNODE p=pHead;
	int i,n=0;//i�������ţ�n:���ҵ���val�ĸ��� 
	while(p->pNext!=NULL&&n<num)
	{
		p=p->pNext;
		i++;
		if(p->value==val)
		{
			n++;
		}
		if(n==num)
		{
			printf("%d",i);
			return;
		}
	}
	if(p->pNext==NULL)
	{
		printf("-1");
		return;
	}
}

int find_value_of_node(PNODE pHead,int n)
{
	int i;
	PNODE p=pHead->pNext;
	for(i=1;i<=n;i++)
	{
		p=p->pNext;
	}
	
	return(p->value);
}

void change_value_of_node(PNODE pHead,int n,int val)
{
	int i;
	PNODE p=pHead->pNext;
	for(i=1;i<=n;i++)
	{
		p=p->pNext;
	}
	p->	value=val;
}

void reverse(PNODE pHead)
{
	int n,i,t;
	PNODE p=pHead;
	while(p->pNext!=NULL)
	{
		p=p->pNext;
		i++;
	}//ͳ�������ܵĽ���� 
	n=i;
	for(i=1;i<=n/2;i++)
	{
		t=find_value_of_node(pHead,i);//�ҵ���i���������ݣ��ݴ�t 
		change_value_of_node(pHead,i,find_value_of_node(pHead,n-i));//�ѵ�i������е�����Ϊ��n-i���е� 
		change_value_of_node(pHead,n-i,t);//�ѵ�n-i������еĸ�Ϊt 
	}
	return;
}




