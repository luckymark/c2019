#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int maze(int n);
void map(char (*pmap)[50]);
void move(int act, int* a, int *b, char (*pmap)[50]);
void push_box(int act, int* a, int *b, char (*pmap)[50]);
void checkstar(int* s_xst,int *s_yst,char (*pmap)[50]);//��*λ��ֻ��*��o����״̬ 
int judge(int* s_xst,int *s_yst,char (*pmap)[50]);
void get_map(int n,char(*mapp)[50]);
void get_lc(int* s_xst,int *s_yst,char(*mapp)[50]);//�궨�յ�λ�� 
int get_stars(char (*mapp)[50]);//�õ�Ŀ��λ��һ���м���
extern int score;
