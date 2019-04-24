#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct List
{
	char name[30];
	int quantity;
	List *next;
};

int sum;

int menu();

void SetPosition(int x, int y);

int LoadInfo(List *head);

void PrintList(List *head);

List *Add(List *head);

List *Delete(List *head);

void Save(List *head);

void FreeLoaded(List *head);

int main()
{
	CONSOLE_CURSOR_INFO cursor = { 100, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	int i;
	List *head;
	head = (List*)malloc(sizeof(List));
	sum = LoadInfo(head);
	if (sum == 0)
	{
		goto po2;
	}
	po1:
	i = menu();
	system("cls");
	switch (i)
	{
	case 1:PrintList(head); break;
	case 2:po2: head = Add(head); break;
	case 3:head = Delete(head); break;
	case 4:Save(head); break;
	case 5:FreeLoaded(head); return 0;
	}
	system("cls");
	goto po1;
}

int LoadInfo(List *head)
{
	List *node;
	List *p;
	List *tail;
	int len;
	int n = 1;
	char ch;
	node = head;
	FILE *fp;
	fp = fopen("List.txt", "r");
	if (fgetc(fp)==EOF)
	{
		printf("Empty warehouse! Add somrthing now!\n");
		return 0;
	}
	fseek(fp, 0, SEEK_SET);
	while (true)
	{
		if (fgets(node->name, 30, fp) == NULL)
		{
			tail->next = NULL;
			free(p);
			--n;
			return n;
		}
		fscanf(fp, "%d\n", &node->quantity);
		len = strlen(node->name);
		node->name[len - 1] = '\0';
		p = (List*)malloc(sizeof(List));
		node->next = p;
		tail = node;
		node = p;
		++n;
	}
	fclose(fp);
}

int menu()
{
	SetPosition(8, 2);
	printf("Goods List!");
	SetPosition(5, 4);
	printf("1. Print List");
	SetPosition(5, 5);
	printf("2. Add Goods");
	SetPosition(5, 6);
	printf("3. Remove Goods");
	SetPosition(5, 7);
	printf("4. Save List");
	SetPosition(5, 8);
	printf("5. Exit");
	SetPosition(2, 4);
	printf("->");
	int x = 2;
	int y = 4;
	clock_t t = clock();
	while (GetKeyState(VK_RETURN) >= 0)
	{
		if (GetKeyState(VK_UP) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (y != 4)
				{
					SetPosition(x, y);
					printf("  ");
					--y;
					SetPosition(x, y);
					printf("->");
				}
				else
				{
					SetPosition(x, y);
					printf("  ");
					y = 8;
					SetPosition(x, y);
					printf("->");
				}
			}
		}
		else if (GetKeyState(VK_DOWN) < 0)
		{
			if (clock() - t > 200)
			{
				t = clock();
				if (y != 8)
				{
					SetPosition(x, y);
					printf("  ");
					++y;
					SetPosition(x, y);
					printf("->");
				}
				else
				{
					SetPosition(x, y);
					printf("  ");
					y = 4;
					SetPosition(x, y);
					printf("->");
				}
			}
		}
	}
	switch (y)
	{
	case 4:return 1; break;
	case 5:return 2; break;
	case 6:return 3; break;
	case 7:return 4; break;
	case 8:return 5; break;
	}
}

void SetPosition(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PrintList(List *head)
{
	int i = 1;
	List *node;
	clock_t t = clock();
	node = head;
	while (true)
	{
		if (node->next == NULL)
		{
			printf("No.%d goods is %s. Its quantity is %d\n", i, node->name, node->quantity);
			printf("Press Esc to continue...\n");
			while (GetKeyState(VK_ESCAPE) >= 0);
			return;
		}
		printf("No.%d goods is %s. Its quantity is %d\n", i, node->name, node->quantity);
		node = node->next;
		++i;
	}
}

void FreeLoaded(List *head)
{
	List *note;
	List *p;
	note = head;
	while (true) 
	{
		if (note->next == NULL)
		{
			free(note);
			return;
		}
		p = note->next;
		free(note);
		note = p;
	}
}

List *Add(List *head)
{
	List *node;
	List *p;
	int i, n, len;
	printf("Now we have %d kind(s) of goods\n", sum);
	printf("Enter the Position you want to add...\n");
po2:
	node = head;
	scanf("%d", &n);
	if (n > sum + 1)
	{
		printf("Wrong! Try again...\n");
		goto po2;
	}
	for (i = 1; i < n - 1; ++i)
	{
		if (i == sum)
		{
			break;
		}
		node = node->next;
	}
	p = (List*)malloc(sizeof(List));
	printf("Please Enter the name of good you want to add...\n");
	while (getchar() != '\n');
	fgets(p->name, 30, stdin);
	len = strlen(p->name);
	p->name[len - 1] = '\0';
	printf("Please Enter the quantity of good you want to add...\n");
	scanf("%d", &p->quantity);
	if (n == 1)
	{
		if (sum == 0)
		{
			head = p;
			p->next = NULL;
			sum++;
			goto po3;
		}
		p->next = head;
		head = p;
		++sum;
		goto po3;
	}
	else if (n == sum + 1)
	{
		p->next = NULL;
	}
	else
	{
		p->next = node->next;
	}
	node->next = p;
	++sum;
po3:
	printf("Press Shift to add another good...\nPress Esc to back to the Menu...\n");
	while (true)
	{
		if (GetKeyState(VK_ESCAPE) < 0)
		{
			return head;
		}
		if (GetKeyState(VK_SHIFT) < 0)
		{
			printf("Now we have %d kind(s) of goods\n", sum);
			printf("Enter the Position you want to add...\n");
			goto po2;
		}
	}
}

List *Delete(List *head)
{
	int n, i;
	n - 0;
	List *node1, *p, *node2;
	printf("Now we have %d kind(s) of goods\n", sum);
	printf("Enter the node you want to delete...");
po1:
	node1 = head;
	node2 = head->next;
	scanf("%d", &n); if (n > sum + 1)
	{
		printf("Wrong! Try again...\n");
		goto po1;
	}
	for (i = 1; i < n - 2; ++i)
	{
		node2 = node2->next;
		node1 = node1->next;
	}
	if (n == 1)
	{
		free(node1);
		head = node2;
		sum--;
	}
	else
	{
		node1->next = node2->next;
		free(node2);
		sum--;
	}
	printf("Done!\n");
	printf("Press Shift to delete another good...\nPress Esc to back to the Menu...\n");
	while (true)
	{
		if (GetKeyState(VK_ESCAPE) < 0)
		{
			return head;
		}
		if (GetKeyState(VK_SHIFT) < 0)
		{
			printf("Now we have %d kind(s) of goods\n", sum);
			printf("Enter the node you want to delete...\n");
			goto po1;
		}
	}
}

void Save(List *head)
{
	FILE *fp;
	List *node;
	node = head;
	fp = fopen("List.txt", "w");
	if (fp == NULL)
	{
		printf("GG\n");
		return;
	}
	while (true)
	{
		if (node->next == NULL)
		{
			fprintf(fp, "%s\n", node->name);
			fprintf(fp, "%d", node->quantity);
			printf("Done\n");
			clock_t t = clock();
			while (clock() - t < 1000);
			return;
		}
		fprintf(fp, "%s\n", node->name);
		fprintf(fp, "%d\n", node->quantity);
		node = node->next;
	}
}