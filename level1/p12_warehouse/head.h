#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define TYPEN 10
struct good
{
	char type[TYPEN];
	int num;
};
void cls();
int getdata(good *a);
int getchoice();
void disphouse(good *a,int n);
void inhouse(good *a,int *p);
void outhouse(good *a,int *p);
void savedata(good *a,int n);
