typedef struct List
{
	int value;//数据域
	struct List * pNext;//指针域，因为要指向下一个结点，所以这个pNext指针必须是 List * 类型的
}NODE,* PNODE;

PNODE create(void) 
{
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//先给首结点分配空间,不存放有效数据

	
	int i,len,val;//len:需要创建的链表有效结点数,val:临时存放用户输入的当前结点的值
	PNODE pTail = pHead;//pTail的功能见后面
	pHead->pNext=NULL;
	pTail->pNext = NULL;

	if (pHead == NULL)//分配失败
	{
		printf("Failed to allocate,program stop soon!");
		exit(-1);
	}
	
	
	printf("input how many values:\n");
	scanf("%d", &len);//获取需要创建的链表有效结点数（因为头结点一般不认为是有效结点）
	if(len>=0)
	{
	  for (i = 0; i < len; i++)
		{
			printf("Input NO.%d value:",i + 1);//数据结构一般符合人类习惯，不用像数组一样下标-1
			scanf("%d", &val);//还没有分配空间给当前数据，暂时存放于val中

			PNODE pNew= (PNODE)malloc(sizeof(NODE));//给这个数据分配空间,用pNew表示这个新空间的地址
			if (pNew== NULL)//分配失败
			{
				printf("Failed to allocate,program stop soon!");
				exit(-1);
			}
			pNew->value = val;//将val的值存入链表中
			pTail->pNext = pNew;//错误的写法：pHead->pNext = pNew;导致所有结点都挂在pHead！ 
			                 //将新创建的结点挂到原链表的最后一个结点的后面，假设有一个指针pTail时刻指向尾结点，那么只需pTail->pNext=pNew即可
			pNew->pNext = NULL;//此时新结点是最后一个结点，指向NULL
			pTail = pNew;//再次将pTail移动到指向最后一个结点
		}
	}
	else
	{
		printf("Error!");
	}

	return pHead;//返回值为首结点的地址，这样就便于对链表进行操作
}

void print_all(PNODE pHead)//遍历链表并输出
{
	PNODE p=pHead->pNext;//将p指向头结点 
	
	while(p!=NULL)//没有指向最后一个结点/链表中只有头结点 
	{
		printf("%d ",p->value);
		p=p->pNext;//移位 
	}
	printf("\n");//结束后换行 
	
	return;
}

void find_value(PNODE pHead,int val,int num)
{
	PNODE p=pHead;
	int i,n=0;//i：结点序号；n:已找到的val的个数 
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
	}//统计链表总的结点数 
	n=i;
	for(i=1;i<=n/2;i++)
	{
		t=find_value_of_node(pHead,i);//找到第i个结点的数据，暂存t 
		change_value_of_node(pHead,i,find_value_of_node(pHead,n-i));//把第i个结点中的数改为第n-i个中的 
		change_value_of_node(pHead,n-i,t);//把第n-i个结点中的改为t 
	}
	return;
}




