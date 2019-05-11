//
// Created by admin on 2019/5/4.
//
// read goods in warehouse, create a linked list
// stack

#include <stdio.h>
#include <stdlib.h>
#include "warehouse.h"

long getStart(FILE *fp);
long getCur(FILE *fp);
long getEnd(FILE *fp);

GOODS* list(){
    GOODS *head;
    head = (GOODS*)malloc(sizeof(GOODS));
    head->next = NULL;

    FILE *fp = fopen(PATH, "r");
    if(fp == NULL){
        printf("Cannot find the file \"goodsList.txt\"");
        exit(EOF);
    }

    long cur = getStart(fp);
    long end = getEnd(fp);
    fseek(fp, 0, SEEK_SET);

    while(cur != end){
        fscanf(fp, "%s", head->type);
        fgetc(fp);
        fscanf(fp, "%d", &head->num);
        fgetc(fp);

        GOODS *newGoods = (GOODS*)malloc(sizeof(GOODS));
        newGoods->next = head;
        head = newGoods;

        cur = getCur(fp);
    }

    fclose(fp);

    return head;
}
