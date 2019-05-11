#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "warehouse.h"

GOODS* putout(GOODS *head){
    char t[TYPE_LEN];
    int n;
    printf("Please enter the needed type of the needed goods:\n");
    scanf("%s", t);
    getchar();
    printf("Please enter the needed number of the goods:\n");
    scanf("%d", &n);
    getchar();

    GOODS *p, *q;
    for(q = head, p = head->next; p != NULL; p = p->next, q = q->next){
        if(strcmp(t, p->type) == 0){
            if(n <= p->num){
                p->num = p->num - n;
                printf("Outbound successfully.\n");
                printf("Type \"%s\" remains %d.\n", p->type, p->num);
                // delete node
                if(p->num == 0){
                    q->next = p->next;
                }
            }
            else{
                printf("Understock!\n");
            }
            return head;
        }
    }

    printf("Goods not found.\n");
    return head;
}
