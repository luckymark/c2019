#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int maze(int n);
void map(char (*pmap)[50]);
void move(int act, int* a, int *b, char (*pmap)[50]);
void push_box(int act, int* a, int *b, char (*pmap)[50]);
void checkstar(int* s_xst,int *s_yst,char (*pmap)[50]);//让*位置只有*和o两种状态 
int judge(int* s_xst,int *s_yst,char (*pmap)[50]);
void get_map(int n,char(*mapp)[50]);
void get_lc(int* s_xst,int *s_yst,char(*mapp)[50]);//标定终点位置 
int get_stars(char (*mapp)[50]);//得到目标位置一共有几个
extern int score;
