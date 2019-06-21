#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int key;
	struct node* next;
}Node;

Node *nil;

void Init(void)
{
	nil=(Node*)malloc(sizeof(Node));
	nil->next=nil;
	nil->key=0;
}

void Insert(int key)
{
	Node* x=(Node*)malloc(sizeof(Node));
	x->key=key;
	x->next=nil->next;
	nil->next=x;
	(nil->key)++;
}

Node* listsearch(const int key, Node* begin, int *order)
{
	Node* cur= begin->next;
	(*order)++;
	while (nil!=cur && key!=cur->key)
	{
		cur=cur->next;
		(*order)++;
	}
	
	return cur;
}

void Inverse(void)
{
	Node *alog, *blog, *clog;
	
	clog=alog=nil;
	
	do
	{
		blog=alog->next;
		alog->next=clog;
		clog=alog;
		alog=blog;
	}
	while (nil!=alog);
	//nil->1->2->nil
	alog->next=clog;
	
}


	
int main(void)
{
	int n, key, i, flag=5;
	
	scanf("%d", &n);
	Init();
	
	Node *wr=nil;
	for (i=0; i<n; i++)
	{
		scanf("%d", &key);
		Insert(key);
	}
	
	printf("Original order:\n");
	do 
	{
		wr=wr->next;
		printf("%d\n", wr->key);
	}
	while (nil!=wr->next);
	
	Inverse();
	
	printf("The order after the Inverse:\n");
	for (i=0; i<(nil->key); i++)
	{
		printf("%d\n", wr->key);
		wr=wr->next;
	}

	int order=0;
	printf("The order of the first flag:\n");
	Node *cur=listsearch(flag, nil, &order);
	printf("%d\n", nil==cur?-1:order);
	
	printf("The order of the second flag:\n");
	cur=listsearch(flag, cur, &order);
	printf("%d", nil==cur?-1:order);

	return 0;
}