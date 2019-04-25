#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define N 15
#define L 4
#define BLACK 1
#define WHITE 2
#define TITLE "Îå×ÓÆå"
void cls();
void init(char board[N][N][L]);
void printboard(char board[N][N][L]);
int winner(char board[N][N][L]);
void PlayerPos(char board[N][N][L]);
void AIPos(char board[N][N][L]);
void gotomn(int m,int n);
