#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define N 15
#define L 4
#define BLACK 1
#define WHITE 2
#define BC -15
#define WC -16
#define TITLE "Îå×ÓÆå"
struct LastPoint
{
	int m;
	int n;
};

extern struct LastPoint Blast,Wlast;
void cls();
void init(char board[N][N][L]);
void printboard(char board[N][N][L]);
int winner(char board[N][N][L]);
void PlayerPos(char board[N][N][L]);
void AIPos(char board[N][N][L]);
void gotomn(int m,int n);

#endif
