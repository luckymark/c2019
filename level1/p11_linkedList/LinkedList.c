#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXN 20
#define MAXNUM 10
#define LEN sizeof(struct LinkNode)

struct LinkNode
{
	int Value;
	struct LinkNode *Nxt;
}*Head, *Tail;

void AddNode(int _val)
{
	struct LinkNode *_newnode;
	_newnode = (struct LinkNode *)malloc(LEN);
	_newnode->Value = _val;
	_newnode->Nxt = NULL;
	Tail->Nxt = _newnode;
	Tail = _newnode;
}

void Traversal()//2
{
	struct LinkNode *Now = Head;
	while (Now != NULL)
	{
		printf("%d ", Now->Value);
		Now = Now->Nxt;
	}
	printf("\n");
}

void RevNode(struct LinkNode *Now)//3
{
	if (Now->Nxt != NULL)
	{
		RevNode(Now->Nxt);
		Now->Nxt->Nxt = Now;
	}
	else Head = Now;
}

void Reverse()//3
{
	Tail = Head;
	RevNode(Head);
	Tail->Nxt = NULL;
}

int FindNode(int _val, int _t)//4
{
	int id = 0;
	struct LinkNode *Now = Head;
	while (Now != NULL)
	{
		if (Now->Value == _val)_t--;
		if (!_t)return id;
		Now = Now->Nxt; id++;
	}
	return -1;
}

int GetRand(int LowerBound, int UpperBound)
{
	return rand() % (UpperBound - LowerBound + 1) + LowerBound;
}

int GetRandNum()
{
	if (GetRand(1, 4) == 1)return 5;
	return GetRand(1, MAXNUM);
}

void init()
{
	Head = Tail = NULL;
	srand(time(NULL));
	int n = GetRand(5, MAXN);
	for (int i = 0; i < n; ++i)
	{
		if (!i)
		{
			Head = Tail = (struct LinkNode *)malloc(LEN);
			Head->Nxt = NULL;
			Head->Value = GetRandNum();
		}
		else AddNode(GetRandNum());
	}
}

int main()
{
	init();
	printf("The list is:\n");
	Traversal();
	Reverse();
	printf("The reversed list is:\n");
	Traversal();
	printf("The serial number of the first node that has a value of 5 is %d(reversed)\n", FindNode(5, 1));
	printf("The serial number of the second node that has a value of 5 is %d(reversed)\n", FindNode(5, 2));
	return 0;
}
