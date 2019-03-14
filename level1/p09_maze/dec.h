#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAPM 10
#define MAPN 21
extern struct point
{
	int x;
	int y;
}player;
extern char map[MAPM][MAPN];					//map of maze
extern char playerpos[MAPM][MAPN];				//player's position
void cls();										//clear screen
void clm(char map[MAPM][MAPN]);					//clear map
void creatm();									//creat map
void printm();									//print map
void indir();									//input direction
