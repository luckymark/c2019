#ifndef _GOMOKU_H
#define _GOMOKU_H
#include<stdio.h>
#include<string.h>
char map[20][20];
char chess[20];//储存棋面某一方向信息
void drawmap();//绘制棋局
void showmap();//显示棋局
void computer(int* x,int* y);//得出计算机落子位置
int score_x_y(int x,int y);//计算位置（x,y）下子得分
int score(int m,int n,int l,int r);//计算得分
int chesstype(int count);//判断某一方向棋局种类
int judge(int x,int y);//判断输赢
int dfs(int x,int y,int dx,int dy);//判断连珠个数
#endif

