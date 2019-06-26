// to find the first position of some value
// (if you've found this value in a previous order, return the next position;
// if you've found all of this value, return the first position)

#include<stdio.h>
#include "linkedList.h"

extern int num;

int find(NODE *head){
    // input
    int n;
    printf("Please input the value you'd like to find:\032");
    scanf("%d", &n);
    getchar();

    // to find
    NODE *p;
    for(p = head; p->next != NULL; p = p-> next){
        if(p->value == n && p->isVisit == FALSE){
            p->isVisit = TRUE;
            return p->number;
        }
    }
    for(p = head; p->next != NULL; p = p-> next){
        if(p->value == n){
            p->isVisit = FALSE;
        }
    }
    for(p = head; p->next != NULL; p = p-> next){
        if(p->value == n){
            p->isVisit = TRUE;
            return p->number;
        }
    }

    return -1;
}
