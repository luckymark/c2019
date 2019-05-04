#include<stdio.h>
#include<stdlib.h>
#include "linkedList.h"

int num = 0;    // the number of nodes

void instruction();
NODE* add(NODE *last);
void traverse(NODE *head);
NODE* reverse(NODE *head, NODE *last);
int find(NODE *head);

int main(){
    // to create a linked list
    // the last node of this linked list is null
    NODE *head, *last;
    head = (NODE*)malloc(sizeof(NODE));
    last = head;
    last -> next = NULL;

    // to enable users to input a series of orders
    instruction();
    char order = 'a';
    NODE *temp;
    int index;
    while(order != 'e') {
        // to request to input an order
        order = getchar();
        getchar();

        // to implement the order
        switch(order){
            case 'a': last = add(last);
                      break;
            case 't': traverse(head);
                      break;
            case 'r': temp = head;
                      head = reverse(head, last);
                      last = temp->next;
                      break;
            case 'f': index = find(head);
                      printf("%d\n", index);
                      break;
            case 'e': break;
            default: printf("Invalid order!\n");
                     break;
        }
    }

    return 0;
}
