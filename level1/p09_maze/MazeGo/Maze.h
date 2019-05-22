#pragma once
//the headerfile that will be used in the main program
#include "hlibrary.h"
#include "material.h"
#include "Queue.h"
#define Pos brick

typedef enum {MASK, ROAD, INWALL, OUTWALL, EMPTY} BrickType;
typedef enum {UP=72, DOWN=80, LEFT=75, RIGHT=77} Operation;

//to clarify the sort of the Maze

void FormMaze(int maze[MAX_LTH][MAX_WTH], brick *start, brick *over);
void InitShape(void);
void clearMask(int x, int y);
bool InMaze(int x, int y);
void updateMaze(int a[MAX_LTH][MAX_WTH]);
void hideCursor(void);
void GoToxy(int x, int y);
void ShowBrick(int maze[MAX_LTH][MAX_WTH]);
void Initposition(Pos * pos);
void GameAndFun(Pos *curpos, int maze[MAX_LTH][MAX_WTH]);