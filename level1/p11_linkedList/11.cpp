#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAXN 20 
#define MAXNUM 10 
#define LEN sizeof(struct LinkNode)

struct LinkNode
{
	int Value;
	struct LinkNode *Next;
}*Head, *Tail;

int Rand_Get(int Rand_Min, int Rand_Max)
{
	return rand() % (Rand_Max - Rand_Min + 1) + Rand_Min;
}

int Get_Num()
{
	if (Rand_Get(1, 4) == 1)return 5;
	return Rand_Get(1, MAXNUM);
}

void AddNode(int _val)
{
	struct LinkNode *node_new;
	node_new = (struct LinkNode *)malloc(LEN);
	node_new->Value = _val;
	node_new->Next = NULL;
	Tail->Next = node_new;
	Tail = node_new;
}

void Init_List()
{
	Head = Tail = NULL;
	srand(time(NULL));
	int n = Rand_Get(5, MAXN);
	for (int i = 0; i < n; ++i)
	{
		if (!i)
		{
			Head = Tail = (struct LinkNode *)malloc(LEN);
			Head->Next = NULL;
			Head->Value = Get_Num();
		}
		else AddNode(Get_Num());
	}
}

void Traversal()
{
	struct LinkNode *Now = Head;
	while (Now != NULL)
	{
		printf("%d ", Now->Value);
		Now = Now->Next;
	}
	printf("\n");
}

void Node_Rev(struct LinkNode *Now)
{
	if (Now->Next != NULL)
	{
		Node_Rev(Now->Next);
		Now->Next->Next = Now;
	}
	else Head = Now;
}

void Reverse()
{
	Tail = Head;
	Node_Rev(Head);
	Tail->Next = NULL;
}

int Node_Tofind(int _val, int _t)//4
{
	int id = 0;
	struct LinkNode *Now = Head;
	while (Now != NULL)
	{
		if (Now->Value == _val)_t--;
		if (!_t)return id;
		Now = Now->Next; id++;
	}
	return -1;
}



int main()
{
	Init_List();
	printf("原链表:\n");
	Traversal();
	Reverse();
	printf("反转:\n");
	Traversal();
	printf("第一个等于5的位置 ： %d(reversed)\n", Node_Tofind(5, 1));
	printf("第二个等于5的位置： %d(reversed)\n", Node_Tofind(5, 2));
	return 0;
}
