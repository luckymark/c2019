#ifndef BASIC_H_INCLUDED
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include<stdbool.h>

#define BASIC_H_INCLUDED
#define length 15
#define width 15
#define Maxside 100
#define MIN -0x3f3f3f3f
#define MAX 0x3f3f3f3f
#define depth 6//²ãÊý
#define ONE 1

#define TWO  100
#define THREE  10000
#define FOUR  1000000
#define FIVE  10000000
#define BLOCKED_ONE 1
#define BLOCKED_TWO  10
#define BLOCKED_THREE 1000
#define BLOCKED_FOUR  100000
extern int position_x;
extern int userposition_y;
extern int userposition_x;
extern int count;
extern int time1 ;
extern int position_y;
extern  int board[length][width];
extern char ch;
extern int temp_x;
extern int temp_y;
extern int number;
extern int first3 ;
extern int first;
extern char a;
extern  int point;
extern int position2_x;
extern int position2_y;
extern int board1[15];
extern int first1;
extern int scoreMatrix[length][width];
POINT  positionpoint;
typedef struct positionboard
{
	int x;
	int y;
		
}board_s;
typedef struct emptyboard
{
	board_s board9[width*length];
	int len;
}board_empty;
typedef struct position
{
	int _x;
	int _y;
}boardnode;
typedef struct child
{
	int x;
	int y;
}child;
typedef struct fiveboard
{
	board_s board9[width*length];
	int len;
}five;
typedef struct comfourboard
{
	board_s board9[width*length];
	int len;
}comfour;
typedef struct humfours
{
	board_s board9[width*length];
	int len;
}humfour;
typedef struct humblockedfours
{
	board_s board9[width*length];
	int len;
}humblockedfour;
typedef struct comblockedfours
{
	board_s board9[width*length];
	int len;
}comblockedfour;
typedef struct comtwothrees
{
	board_s board9[width*length];
	int len;
}comtwothree;
typedef struct humtwothrees
{
	board_s board9[width*length];
	int len;
}humtwothree;
typedef struct comthrees
{
	board_s board9[width*length];
	int len;
}comthree;
typedef struct humthrees
{
	board_s board9[width*length];
	int len;
}humthree;
typedef struct comtwos
{
	board_s board9[width*length];
	int len;
}comtwo;
typedef struct humtwos
{
	board_s board9[width*length];
	int len;
}humtwo;
typedef struct neighbor
{
	int _x;
	int _y;
}neighbor;
#endif // BASIC_H_INCLUDED
