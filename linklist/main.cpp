//
//  main.cpp
//  linklist
//
//  Created by 兼桑 on 2019/4/10.
//  Copyright © 2019 兼桑. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
using namespace std;
typedef struct linklist{
    int data;
    struct linklist *next;
}linklist;
linklist *creat_list(int n){
    linklist *head,*node,*end;
    head=(linklist*)malloc(sizeof(linklist));
    end=head;
    for(int i=0;i<n;i++)
    {
        node=(linklist*)malloc(sizeof(linklist));
        node->data=rand()%100;
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}
void reserve(linklist *list,int n){
    linklist *p=list->next,*p2,*add;
    int i=0;
    if(p->next==NULL||p==NULL)//空链表or仅1结
        return;
    while(i<n)
    {
        ++i;
        p2=p->next;
        if(p==list->next)
            p->next=NULL ;//首转尾
        else
        {
            add=p;
            p->next=add;
            p->next=list->next;
            list->next=p;
            p=p2;
        }
    }
    p->next=list->next;
    list->next=p;
}
int main()
{
    int n=20;
    linklist *list=creat_list(n);
    reserve(list,n);
    for(int i=0;i<n;++i)
    {
        if(list->data==5)
            printf("-1");
        list=list->next;
    }
    return 0;
}
