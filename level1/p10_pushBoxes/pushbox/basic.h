#ifndef  BASIC_H_INCLUDED
#define  BASIC_H_INCLUDED
#define MAXPATH 1000
#define Maplong 6
#define Mapwidth 6
#define out_x 2
#define out_y 5

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
int map[Maplong][Mapwidth];
int rmap[Maplong][Mapwidth];
extern int position_x;
extern int box_x ;
extern int box_y ;
extern int position_y;
extern int direction;
extern int scorenumber;
extern int number;
extern int py;//还原移动后的值
extern int px;//
extern char ch;
typedef struct node
{
	int x;
	int y;
}node;
typedef struct path
{
	node num[MAXPATH];
	int top;
}*ppath;
#endif // !BASIC_H_INCLUDED

