#include<stdio.h>
#include<malloc.h>
struct node
{
	int val;
	node *next;
};
node *addnode(node *head);
void freeall(node *p,node **t);
node *reverse(node *p);
void printlist(node *head);
void find5(node *start); 
