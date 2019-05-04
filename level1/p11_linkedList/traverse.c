// to print the value of each node in order

#include<stdio.h>
#include "linkedList.h"

void traverse(NODE *head){
    NODE *p;
    for(p = head; p->next->next != NULL; p = p->next){
        printf("%d->", p->value);
    }
    printf("%d\n", p->value);
}
