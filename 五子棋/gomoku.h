#ifndef _GOMOKU_H
#define _GOMOKU_H
#include<stdio.h>
#include<string.h>
char map[20][20];
char chess[20];//��������ĳһ������Ϣ
void drawmap();//�������
void showmap();//��ʾ���
void computer(int* x,int* y);//�ó����������λ��
int score_x_y(int x,int y);//����λ�ã�x,y�����ӵ÷�
int score(int m,int n,int l,int r);//����÷�
int chesstype(int count);//�ж�ĳһ�����������
int judge(int x,int y);//�ж���Ӯ
int dfs(int x,int y,int dx,int dy);//�ж��������
#endif

