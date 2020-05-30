#include<iostream>
#include<cstdio>

struct node
{
	int number;
	int value;
	node *next;
	node() {next = NULL;}
};

struct linkedList
{
	node *root = NULL;
	node *lastFind = NULL;
	int size;

	void init() {size = 0;}

	void insert(int val)
	{
		if (root == NULL)
		{
			root = new node();
			root->value = val;
			root->number = ++size;
		}
		else
		{
			node *cur = root;
			while (cur->next != NULL)
				cur = cur->next;
			node *tmp = new node();
			tmp->value = val;
			tmp->number = ++size;
			cur->next = tmp;
			tmp->next = NULL;
		}
	}

	void traverse()
	{
		node *cur = root;
		while (cur != NULL)
		{
			printf("%d ", cur->value);
			cur = cur->next;
		}
	}

	int find(node *start, int val)
	{
		node *cur = start;
		while (cur != NULL)
		{
			if (cur->value == val)
			{
				lastFind = cur;
				return cur->number;
			}
			cur = cur->next;
		}
		return -1;
	}

	void reverse()
	{
		node *last = NULL;
		node *cur = root;
		while (cur != NULL)
		{
			node *tmp = cur->next;
			cur->next = last;
			if (tmp == NULL)
			{
				root = cur;
				return;
			}
			last = cur;
			cur = tmp;
		}
	}
};

int main()
{
	linkedList a;
	int n;
	printf("Enter the number of the nodes\n");
	scanf("%d", &n);
	printf("Add nodes\n");
	for (int s = 0; s < n; s++)
	{
		int num;
		scanf("%d", &num);
		a.insert(num);
	}
	printf("Travesal:\n");
	a.traverse();
	printf("\nFind-5 result: %d\n", a.find(a.root, 5));
	printf("Find-5 2nd result: %d\n", a.find(a.lastFind->next, 5));
	printf("\nReversed traversal:\n");
	a.reverse();
	a.traverse();
	printf("\n");
}
