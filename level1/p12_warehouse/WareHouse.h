#if !defined(WareHouse)
#define WareHouse

#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>

struct Goods
{
    char name[100];
    char model[100];
    int quantity;
};

int Print();
int Inport();
int Outport();
int Exit();

#endif
