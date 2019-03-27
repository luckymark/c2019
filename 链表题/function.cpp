#include"linklist.h"
using namespace std;
stack<node*> A;
node* createlinklist_1()
{
	node *p,*ptr;
	p = new node;
	p->value = 0; //头节点
	ptr = p;
	int a;
	while (cin >> a)
	{   
		node *x = new node;
		x->value = a;
		ptr->p = x;
		ptr = x;
	}
	ptr->p = NULL;
	return p;
}

void search5(node *p)     //查找功能
{
	int a = 0;
	for (node *i=p ; i != NULL; i = i->p,a++)
	{
		if (i->value == 5)
			cout << a<<endl;
	}
	
	
}

void fanxu(node *p)
{
	node*x = p->p;
	for (node *i = p->p; i != NULL; i = i->p)
	{
		A.push(i);
	}
	for (; !A.empty();)
	{
		x->p = A.top();
		x = A.top();
		A.pop();

	}
	x->p = NULL;
	for (; p != NULL; p = p->p)
		cout << p->value<<" ";
}
