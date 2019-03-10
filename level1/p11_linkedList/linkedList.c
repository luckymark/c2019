#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list
{
    int num;
    int value;
    struct list *next;
};
void display(struct list *head);
void is_five(struct list *head);
struct list *exchange(struct list *head, int n);
struct list *move(struct list *head, int n);
int main(void)
{
    struct list *_link, *_head, *q;
    int m, i = 0, j;

    _link = q = (struct list *)malloc(sizeof(struct list));

    printf("Now you can start to enter the value.(q to quit)\n");
    _head = NULL;
    while (1 == scanf("%d", &m)&& m!=-1)
    {
        if (0 == i)
        {
            _head = _link;
        }
        else
        {
            _link->next = q;
            _link = q;
        }
        _link->num = i + 1;
        _link->value = m;

        q = (struct list *)malloc(sizeof(struct list));

        i++;
    }
    _link->next = NULL;
    free(q);
    display(_head);
    _head = exchange(_head, i);
    is_five(_head);

    system("pause");

    return 0;
}
void display(struct list *head)
{
    struct list *cp;

    cp = head;
    while (cp != NULL)
    {
        printf("No.%d is %d\n", cp->num, cp->value);
        cp = cp->next;
    }
}
struct list *move(struct list *head, int n)
{
    struct list *cp;
    int i;

    cp = head;
    for (i = 0; i < n - 1; i++)
    {
        cp = cp->next;
    }

    return cp;
}
struct list *exchange(struct list *head, int n)
{
    struct list *ch1, *ch2;
    int i;

    ch1 = head;
    ch2 = move(ch1, n);
    head = ch2;
    for (i = n; i > 1; i--)
    {
        ch2->next = move(ch1, i - 1);
        ch2 = ch2->next;
    }
    ch2->next = NULL;

    return head;
}
void is_five(struct list *head)
{
    struct list *ch;
    bool flag = 0;
    ch = head;
    while (ch != NULL)
    {
        if (5 == ch->value)
        {
            printf("%d\n", ch->num);
            flag = 1;
        }
        ch = ch->next;
    }

    if (!flag)
    {
        printf("-1\n");
    }
}