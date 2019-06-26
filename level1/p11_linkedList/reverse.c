// to reverse the current linked list and print the value of each node in order

#include<stdio.h>
#include "linkedList.h"

extern int num;

void traverse(NODE *head);

NODE* reverse(NODE *head, NODE *last){
    // each loop, insert the first node after the "last" one, and point the head pointer to the next one
    NODE *temp = head;
    NODE *p1 = NULL, *p2;
    for(; head != last;){
        last->next = head;
        p2 = head->next;
        head->next = p1;
        p1 = head;
        head = p2;
    }

    // insert the null node into the end of the linked list
    temp->next = last;
    head = head->next;
    last->next = NULL;

    // change the index of the nodes
    NODE *p;
    for(p = head; p->next != NULL; p = p->next){
        p->number = num - p->number + 1;
    }

    // print
    traverse(head);

    return head;
}
