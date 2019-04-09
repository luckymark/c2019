#include<stdio.h>
typedef struct Node {
	int value;
	struct Node *next;
}list, *linklist;
linklist creat(int num_node);
void search(linklist list);
linklist reverse(linklist list);
int main() {
	int num_node;
	int goal = -1;
	list *L;
	printf("请输入链表的节点数:");
	scanf_s("%d", &num_node);
	L = creat(num_node);
	L = reverse(L);
	search(L);
	system("pause");
	return 0;
}
linklist creat(int num_node) {
	linklist first, p, n;
	first = (list*)malloc(sizeof(list));
	if (!first)return 0;
	first->next = NULL;
	p = first;
	for (int i = 1; i <= num_node; i++) {
		n = (list*)malloc(sizeof(list));
		printf("请输入第%d个节点的值:", i);
		scanf_s("%d", &(n->value));
		n->next = NULL;
		p->next = n;
		p = n;
	}
	return first;
}
void search(linklist list) {
	int i = 0, b = 0;
	linklist L = list;
	do {
		L = L->next;
		i++;
		if (L->value == 5) {
			b = 1;
			printf("%d", i);
		}
	} while (L->next != NULL);
	if (b = 0)printf("-1");
}
linklist reverse(linklist list) {
	linklist p = list, q, r;
	q = p->next;
	r = q->next;
	p = NULL;
	do {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	} while (r != NULL);
	q->next = p;
	r = (linklist)malloc(sizeof(list));
	r->next = q;
	return r;
}