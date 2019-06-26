#include"basic.h"
#include"map.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int win(char(*map)[15]);//已经完成则返回1，没有则返回0

int move(char(*map)[15]);

void move_onstep(char *play, char *forward1, char *forward2,int * score);//play是玩家当前所在的格子，forward1是前进方向的第一格，forward2是第二格，根据不同情况决定移动后的操作

void main_menu(void);

void game_menu(void);

void record(int number, int score);//记录分数 