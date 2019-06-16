#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void newmap(char map[15][15][4]);
void move(int *m,int *n,char map[15][15][4],int a[][15],int *c);
void change_1(int *m,int *n,char map[15][15][4],int a[][15]);
void change_2(int *m,int *n,char map[15][15][4],int a[][15]);
void change_3(int *m,int *n,char map[15][15][4],int a[][15]);
void change_4(int *m,int *n,char map[15][15][4],int a[][15]);
void confirm(int *m,int *n,char map[15][15][4],int a[][15],int *c);
int win(int *m,int *n,int a[][15],int count,int side);

#endif





