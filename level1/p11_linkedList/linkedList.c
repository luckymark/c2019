#include <stdio.h>
#include <stdlib.h>

struct LinkNode
{
    int value;
    LinkNode *next; 
};
int main()
{
    int length = 10;
    int i;
    
    //1.init,2.traversal
    LinkNode *list, *temp;
    for (i = 0; i < length; i++)
    {
        LinkNode *l = (LinkNode *)malloc(sizeof(length));
        i != 0 ? (temp->next = l) : list = l;
        l->value = i;
        temp = l;
    }
    temp->next = 0;

    //3.reserve
    LinkNode *l;
    temp = list;
    for (i = 0; i < length - 1; i++)
    {
        l = list->next;
        list->next = list->next->next;
        l->next = temp;
        temp = l;
    }
    list = temp;

    //4&5.find node->value = 5
    int times = 0;
    temp = list;
    for (i = 0; i < length; i++)
    {
        if (temp->value == 5)
        {
            printf("%s index:%d\n", times == 0 ? "First" : "Second", i);
            times++;
        }
        temp = temp->next;
    }
    times == 1 && printf("Second index:%d\n", -1);

    return 0;
}