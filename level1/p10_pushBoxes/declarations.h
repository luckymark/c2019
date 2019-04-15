#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAXN 10000
extern int step;
extern int h;
extern char map[MAXN];
extern char boxpos[MAXN];
extern struct point
{
	int m;
	int n;
}player;
void indir();
void getmap();
int finish();
void cls();
int maplength();
void printmap();
