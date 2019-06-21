#include<stdio.h>
#include<stdlib.h>

typedef struct node {  //�������� 
	int data;
	struct node* next;
}NODE;

NODE* create(int n)   //�������� 
{
	NODE* head, * node, * end,* info;
	head = (NODE*)malloc(sizeof(NODE));
	end = head;
	info = (NODE*)malloc(sizeof(NODE));
	info->data = n;
	end->next = info;
	end = info;
	for (int i = 0; i < n; i++) {
		node = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &node->data);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void change(NODE* list, int pos, int n)  //�ı�ڵ��ֵ 
{
	NODE* t = list->next;
	for (int i = 0; i < pos; i++) {
		t = t->next;
		if (t == NULL) {
			puts("��Ч�ڵ�.");
			return;
		}
	}
	t->data = n;
}

void delet(NODE* list, int pos)  //ɾ���ڵ� 
{
	NODE* t = list->next;
	for (int i = 1; i < pos; i++) {
		t = t->next;
		if (t->next == NULL) {
			puts("�ýڵ㲻����.");
			return;
		}
	}
	list->next->data = list->next->data - 1;
	NODE* p = t->next;
	t->next = t->next->next;
	free(p);
}

void insert(NODE* list, int pos, int n)  //����ڵ� 
{
	NODE* t = list->next;
	for (int i = 1; i < pos; i++) {
		t = t->next;
		if (t == NULL) {
			puts("��Ч�ڵ�.");
			return;
		}
	}
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->data = n;
	p->next = t->next;
	t->next = p;
	list->next->data = list->next->data + 1;
}

int find(NODE* list, int numth, int n)  //�����ض�ֵ 
{
	int ct = 1;
	NODE* t = list->next;
	int i = 1;
	while (t->next != NULL) {
		t = t->next;
		if (t->data == n) {
			if (ct == numth) {
				printf("%d\n", i);
				return;
			}
			else {
				ct++;
			}
		}
		i++;
	}
	printf("δ�ҵ���ֵ.\n");
}

void traversal(NODE* list)  //�������� 
{
	NODE* t = list->next;
	printf("������Ϊ:%d\n", t->data);
	while (t->next != NULL) {
		t = t->next;
		printf("%d ", t->data);
	}
}

void reversal(NODE* list)  //������
{
	NODE* L, * cur, * p;
	L = list->next;
	if (L == NULL || L->next == NULL) {
		return NULL;
	}
	cur = L->next;
	while (cur->next != NULL) {
		p = cur->next;
		cur->next = p->next;
		p->next = L->next;
		L->next = p;
	}
	return list;
}

int main()
{
	NODE* list = create(3);
	traversal(list);
	reversal(list); 
	find(list, 1, 5);
	find(list, 2, 5);
	return 0;
}
