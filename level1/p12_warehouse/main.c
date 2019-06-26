#include<stdio.h>
#include "warehouse.h"

void menu();
void query(GOODS *head);
GOODS* putin(GOODS *head);
GOODS* putout(GOODS *head);
GOODS* list();
void rewrite(GOODS *head);

int main(){
    // print menu
    menu();

    // read goods in warehouse, create a linked list
    // head is a null struct
    GOODS *head;
    head = list();

    // implement instructions
    int order = 1;
    while(order){
        printf("\nPlease enter an order:\n");
        scanf("%d", &order);

        switch(order){
            case 1: query(head);
                    break;
            case 2: head = putin(head);
                    break;
            case 3: head = putout(head);
                    break;
            case 0: break;
            default: printf("Invalid order!\n");
                     break;
        }
    }

    // output the goods list in file
    rewrite(head);

    return 0;
}
