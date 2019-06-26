// to add a node

#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

extern int num;

NODE* add(NODE* last){
    ++num;
    last->number = num;

    last->isVisit = FALSE;

    printf("Please input the value of the new node:\n");
    scanf("%d", &last->value);
    getchar();

    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    last -> next = newNode;
    last = newNode;
    last -> next = NULL;

    return last;
}
