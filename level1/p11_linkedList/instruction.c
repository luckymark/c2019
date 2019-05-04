// to print the instruction of inputting orders

#include<stdio.h>

void instruction(){
    printf("Please input an order according to the following instructions:\n");
    printf("a: to add a node\n");
    printf("t: to print the value of each node in order\n");
    printf("r: to reverse the current linked list and print the value of each node in order\n");
    printf("f: to find the first position of some value\n(if you've found this value in a previous order, return the next position;\nif you've found all of this value, return the first position)\n");
    printf("e: to exit this program\n");
}
