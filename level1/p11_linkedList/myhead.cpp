#include<iostream>
#include<conio.h>
struct node
{
	int num=0;
	node* next;
};
using namespace std;
node* make(node* head);
void print(node* head);
int find(node* head,int target,int position);
node* reverse(node *head);
