#include"basic.h"
#include"map.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int win(char(*map)[15]);//�Ѿ�����򷵻�1��û���򷵻�0

int move(char(*map)[15]);

void move_onstep(char *play, char *forward1, char *forward2,int * score);//play����ҵ�ǰ���ڵĸ��ӣ�forward1��ǰ������ĵ�һ��forward2�ǵڶ��񣬸��ݲ�ͬ��������ƶ���Ĳ���

void main_menu(void);

void game_menu(void);

void record(int number, int score);//��¼���� 