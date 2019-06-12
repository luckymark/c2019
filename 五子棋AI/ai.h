#ifndef AI_H
#define AI_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void ai(int *m,int *n,char map[15][15][4],int a[][15]);
void search_1(int *m,int *n,char map[15][15][4],int a[][15]);
void search_2(int *m,int *n,char map[15][15][4],int a[][15]);
void search_3(int *m,int *n,char map[15][15][4],int a[][15]);
void search_4(int *m,int *n,char map[15][15][4],int a[][15]);
int win(int *m,int *n,int a[][15],int count,int side);
int score_1(int m,int n,int a[][15],int side);
int score_2(int m,int n,int a[][15],int side);
int live(int m,int n,int a[][15],int count,int side);
int dead(int m,int n,int a[][15],int count,int side);
int twodead(int m,int n,int a[][15],int count,int side); 
int generate_1(int b[][15],int side) ;
int generate_2(int b[][15],int side) ;
int sumscore_1(int a[][15],int side); 
int sumscore_2(int a[][15],int side);
int cut(int x,int y,int b[][15]);
void same_to_a(int a[][15],int b[][15]);
#endif
