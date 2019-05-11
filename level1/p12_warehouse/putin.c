#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "warehouse.h"

GOODS* list();
long getEnd(FILE *fp);
long getCur(FILE *fp);

GOODS* putin(GOODS *head){
    char t[TYPE_LEN];
    int n;
    printf("Please put in the new goods' type:\n");
    scanf("%s", t);
    getchar();
    printf("Please put in the new goods' num:\n");
    scanf("%d", &n);
    getchar();

    // the added goods already exists
    GOODS *p;
    for(p = head->next; p != NULL; p = p->next){
        if(strcmp(t, p->type) == 0){
            p->num = p->num + n;
            printf("Input successfully.\n");
            printf("Type \"%s\" number: %d.\n", p->type, p->num);
            return head;
        }
    }

    // if a new goods
    head->num = n;
    for(int i = 0; i < TYPE_LEN; ++i){
        head->type[i] = t[i];
    }
    printf("Input successfully.\n");
    printf("Type \"%s\" number: %d.\n", head->type, head->num);

    GOODS *newGoods = (GOODS*)malloc(sizeof(GOODS));
    newGoods->next = head;
    head = newGoods;
    return head;
}
