#ifndef BASIC_H_INCLUDED
#define BASIC_H_INCLUDED
#define LEN sizeof(struct storage)
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct storage
{
    char name[10];
    double weight;
} cargo[100];


#endif // BASIC_H_INCLUDED
