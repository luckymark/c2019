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
	//��������ڵ㣻
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
	//���½ڵ㸳ֵ��
	pn = node;
	printf("��Ϊ����ڵ�����ֵ��\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &pn->data);
		pn = pn->next;
	}
	//���½ڵ㷴��
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
	printf("�ڵ��ѷ���\n���ڲ���ֵΪ5�Ľڵ���ţ�\n");
	//������������ֵ��
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