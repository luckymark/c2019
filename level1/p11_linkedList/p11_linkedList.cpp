#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

typedef struct linkedList 
{
	int value;
	linkedList *next;
};

linkedList *mark;

linkedList *reverse(linkedList *head);

void LoadLinkedList(linkedList* head);

void DeleteLinkedList(linkedList *head);

int FindFive(linkedList *note);

int main()
{
	int n = 1;
	int a;
	int j;
	linkedList *head;
	linkedList *pnew;
	linkedList *tail;
	pnew = (linkedList*)malloc(sizeof(linkedList));
	linkedList *p;
	head = pnew;
	while (true)
	{
		printf("Enter your number in No.%d linkedList.\nEnter 0 to quit.\n", n);
		scanf("%d", &a);
		if (a == 0)
		{
			tail->next = NULL;
			free(pnew);
			break;
		}
		pnew->value = a;
		p = (linkedList *)malloc(sizeof(linkedList));
		pnew->next = p;
		tail = pnew;
		pnew = p;
		++n;
	}
	LoadLinkedList(head);
	head = reverse(head);
	printf("\nNow our linkedlist is reversed...\n\n");
	LoadLinkedList(head);
	j = FindFive(head);
	if (j != -1)
	{
		printf("5 is in No.%d note!!!\n", j);
	}
	while (j != -1 && mark != NULL)
	{
		j = FindFive(mark);
		if (j != -1)
		{
			printf("5 is in No.%d note!!!\n", j);
		}
	}
	DeleteLinkedList(head);
	system("pause");
	return 0;
}

void LoadLinkedList(linkedList* head)
{
	linkedList* read;
	read = head;
	int n = 1;
	while (true)
	{
		printf("No.%d %d\n", n, read->value);
		if (read->next == NULL)
		{
			break;
		}
		read = read->next;
		++n;
	}
}

linkedList *reverse(linkedList *head)
{
	linkedList *note;
	linkedList *TrueHead;
	TrueHead = head;
	while (true)
	{
		note = TrueHead->next;
		TrueHead->next = note->next;
		note->next = head;
		head = note;
		if (TrueHead->next == NULL)
		{
			break;
		}
	}
	return head;
}

int FindFive(linkedList *note)
{
	while (true)
	{
		if (note->value == 5)
		{
			mark = note->next;
			return ++count;
		}
		if (note->next == NULL)
		{
			return -1;
		}
		note = note->next;
		count++;
	}
}

void DeleteLinkedList(linkedList *head)
{
	linkedList *note;
	linkedList *p1;
	note = head;
	while (true)
	{
		if (note->next == NULL)
		{
			free(note);
			return;
		}
		p1 = note->next;
		free(note);
		note = p1;
	}
}