#ifndef _PUSHBOX_H
#define _PUSHBOX_H
void gotoxy();
void printmap();
void game();
void record(int count,int level);
#define M 16
#define Totallevel 3
#define WALL 0
#define ROAD 1
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7
#define BOX 8
#define DESTINATION 9
#define CORRECT 10
#define ESC 11
extern int map[Totallevel+1][M][M];
extern int level;
extern int flag;
extern int count;

#endif

