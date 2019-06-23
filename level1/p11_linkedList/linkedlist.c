#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义基本结构
typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
} LinkedList;

//新建
LinkedList *create( int data_1 )
{
    LinkedList *node = NULL;
    node = ( LinkedList *)malloc( sizeof ( LinkedList ));
    if ( node == NULL )
    {
        printf("malloc fail!\n");
    }
    memset( node , 0 ,sizeof( LinkedList ));
    node->data = data_1;
    node->next = NULL;
    return node;
}

//尾插
void tail_insert( LinkedList *pH ,LinkedList *new )
{
    LinkedList *p = pH ;
    while ( NULL != p -> next )
    {
        p = p -> next;
    }
    p -> next = new;
}

//头插
void top_insert( LinkedList *pH ,LinkedList *new )
{
    LinkedList *p = pH;
    new -> next = p -> next;
    p -> next = new;
}

//遍历
void Print_all( LinkedList *pH )
{
    LinkedList *p = pH;
    p = p -> next;
    while ( NULL != p -> next )
    {
        printf("data: %d\n" ,p -> data );
        p = p -> next;
    }
    printf("data: %d\n" ,p -> data);
}

//反序
void trave_list( LinkedList *pH )
{
    LinkedList *p = pH -> next;
    LinkedList *pBack;
    int i = 0;
    if ( p -> next == NULL || p == NULL )
    {
        return 0;
    }
    while ( NULL != p -> next )
    {
        pBack = p -> next;
        if ( p == pH -> next )
        {
            p -> next = NULL;
        }
        else
        {
            p -> next = pH -> next;
        }
        pH -> next = p;
        p = pBack;
    }
    top_insert( pH ,p );
}

//查找
int search( LinkedList *pH ,int data_1 )
{
    int id = 0;
    LinkedList *p = pH;
    p = p -> next;
    while ( NULL != p -> next )
    {
        ++id;
        if ( p -> data == data_1 )
        {
            printf("%d\n" ,id);
        }
        p = p -> next;
    }
    if ( p -> data == data_1 )
    {
        printf("%d\n" ,id + 1);
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    int data;
    LinkedList *node_first = create( 0 );
    for (int i = 0; i < 10; i++)
    {
        tail_insert( node_first ,create( i ));
    }

    Print_all( node_first );
    putchar('\n');
    trave_list( node_first );
    Print_all( node_first );
    putchar('\n');
    search( node_first ,5 );

    return 0;
}
