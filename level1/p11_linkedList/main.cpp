#include<stdio.h>
#include<stdlib.h>

struct linklist
{
	int data;
	struct linklist *next;
};

int main()
{
	linklist *node = (linklist*)malloc(sizeof(linklist));
	linklist *pn = node, *create = NULL;
	//创建五个节点；
	for (int i = 1; i < 6; i++)
	{
		create = (linklist*)malloc(sizeof(linklist));
		pn->next = create;
		pn = pn->next;
		if (i == 5)
		{
			pn->next = NULL;
		}
	}
	//以下节点赋值；
	pn = node;
	printf("请为该五节点链表赋值：\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &pn->data);
		pn = pn->next;
	}
	//以下节点反序；
	pn = node->next;
	create = pn->next;
	for (int i = 1; i < 5; i++)
	{
		pn = node->next;
		node->next = create;
		pn->next = create->next;
		create->next = pn;
		create = pn->next;
	}
	printf("节点已反序；\n正在查找值为5的节点序号：\n");
	//遍历并查找数值；
	for (int i = 1; ; i++)
	{
		if (pn->data == 5)
		{
			printf("%d\n", i);
			if (pn->next == NULL)
			{
				break;
			}
		}
		else if (pn->next == NULL)
		{
			printf("-1\n");
			break;
		}
		pn = pn->next;
	}
	system("pause");
}