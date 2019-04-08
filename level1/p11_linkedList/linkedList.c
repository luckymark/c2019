#include "linkedList.h"

void PutValue(LinkedList *list, int n);
void Converse(LinkedList *list, int n);
int FindValue(LinkedList *list, int n, int aim);

int main(int argc, char const *argv[])
{
    int n = 100, aim = 2;

    LinkedList *head, *node, *end;
    head = (LinkedList *)malloc(sizeof(LinkedList)); //Creat the first one
    end = head;

    for (size_t i = 0; i < n - 1; i++) //Creat the following (n - 1) ones
    {
        node = (LinkedList *)malloc(sizeof(LinkedList));
        end->next = node;
        end = node;
    }
    end->next = NULL;

    PutValue(head, n);
    Converse(head, n);
    FindValue(end, n, aim);

    system("pause");
    return 0;
}

void PutValue(LinkedList *list, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        list->num = i % 7;
        //printf("%d\n", list->num);
        list = list->next;
    }
}

void Converse(LinkedList *list, int n)
{
    LinkedList *set[3];
    set[0] = list;
    set[1] = set[0]->next;
    set[0]->next = NULL;
    set[2] = set[1]->next;
    for (size_t i = 1; i < n - 2; i++)
    {
        //printf("LinkedList[%d] = %d\n", n + 1 - i, set[i % 3]->num);
        set[i % 3]->next = set[(i - 1) % 3];
        set[(i - 1) % 3] = set[(i + 1) % 3]->next;
    }
    set[(n - 2) % 3]->next = set[n % 3];
    set[(n - 1) % 3]->next = set[(n - 2) % 3];
}

int FindValue(LinkedList *list, int n, int aim)
{
    int t;
    for (t = 1; t <= n; t++)
    {
        if (list->num == aim)
        {
            printf("List %d = %d\n", t, aim);
        }
        list = list->next;
    }
    if (t == 0)
    {
        printf("-1");
    }
}