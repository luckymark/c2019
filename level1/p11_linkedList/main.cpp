#include<stdio.h>
#include<stdlib.h>

struct linklist
{
	int data;
	struct linklist *next;
};

int main()
{
	linklist *node0 = (linklist*)malloc(sizeof(linklist)), *node1 = (linklist*)malloc(sizeof(linklist)), *node2 = (linklist*)malloc(sizeof(linklist)), *node3 = (linklist*)malloc(sizeof(linklist)), *node4 = (linklist*)malloc(sizeof(linklist));
	linklist *pn = node0;
	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	//以下节点赋值；
	printf("请为该五节点链表赋值：\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &pn->data);
		pn = pn->next;
	}
	//以下节点反序；人工反序；
	node4->next = node3;
	node3->next = node2;
	node2->next = node1;
	node1->next = node0;
	node0->next = NULL;
	printf("节点已反序；\n正在查找值为5的节点序号：\n");
	//遍历并查找数值；
	pn = node4;
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