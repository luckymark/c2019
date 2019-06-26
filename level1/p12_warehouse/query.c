#include<stdio.h>
#include "warehouse.h"

void query(GOODS *head){
    GOODS *p;
    for(p = head->next; p != NULL; p = p->next){
        printf("type: %s\n", p->type);
        printf("num: %d\n", p->num);
    }
}
