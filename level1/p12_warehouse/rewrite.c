//
// Created by admin on 2019/5/8.
//

#include <stdio.h>
#include<stdlib.h>
#include "warehouse.h"

void rewrite(GOODS *head) {
    FILE *fp = fopen(PATH, "w");
    if (fp == NULL) {
        printf("Cannot find the file \"goodsList.txt\"");
        exit(EOF);
    }

    GOODS *p;
    for (p = head->next; p != NULL; p = p->next) {
        fprintf(fp, "%s\n", p->type);
        fprintf(fp, "%d\n", p->num);
    }

    fclose(fp);
}
