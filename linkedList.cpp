#include<stdio.h>
#include<stdlib.h>

typedef struct node {  //定义链表 
	int data;
	struct node* next;
}NODE;

NODE* create(int n)   //创建链表 
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

void change(NODE* list, int pos, int n)  //改变节点的值 
{
	NODE* t = list->next;
	for (int i = 0; i < pos; i++) {
		t = t->next;
		if (t == NULL) {
			puts("无效节点.");
			return;
		}
	}
	t->data = n;
}

void delet(NODE* list, int pos)  //删除节点 
{
	NODE* t = list->next;
	for (int i = 1; i < pos; i++) {
		t = t->next;
		if (t->next == NULL) {
			puts("该节点不存在.");
			return;
		}
	}
	list->next->data = list->next->data - 1;
	NODE* p = t->next;
	t->next = t->next->next;
	free(p);
}

void insert(NODE* list, int pos, int n)  //插入节点 
{
	NODE* t = list->next;
	for (int i = 1; i < pos; i++) {
		t = t->next;
		if (t == NULL) {
			puts("无效节点.");
			return;
		}
	}
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->data = n;
	p->next = t->next;
	t->next = p;
	list->next->data = list->next->data + 1;
}

int find(NODE* list, int numth, int n)  //查找特定值 
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
	printf("未找到该值.\n");
}

void traversal(NODE* list)  //遍历链表 
{
	NODE* t = list->next;
	printf("链表长度为:%d\n", t->data);
	while (t->next != NULL) {
		t = t->next;
		printf("%d ", t->data);
	}
}

void reversal(NODE* list)  //链表反序
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
