#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include<stdio.h>
#include<assert.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define Maplong   20
#define Mapwidth  20
#define Maxstep  500
int position_x=1;
int position_y=0;
int one=1;
int temp;
int px;
int py;
char ch;
typedef struct position
{
    int _x;
    int _y;
}position;
typedef position mazenode ;
typedef struct Stack
{
    int top;
    mazenode num[Maxstep];
}Stack,*pstack;
typedef struct maze
{
    int _map[Maplong][Mapwidth];
}maze,*pmaze;
void antoprintmaze(pmaze m);
void initmaze(pmaze m,int Map[Maplong][Mapwidth]);
void initstack(pstack m);
void popstack(pstack m);
void pushstack(pstack m,mazenode n );
//void Random();
int Passmaze(pmaze m,position e);
void Footpath(pmaze m,position e);
int emptystack(pstack s);
mazenode Stacktop(pstack s);
int entermaze(pmaze m,position e);
int outmaze(position m,position e);
void printmaze(pmaze m);
void randommaze();
void antoFootpath(pmaze m,position e);
int exitmaze(pmaze m);
void wall(pmaze m);

#endif // MAZE_H_INCLUDED
