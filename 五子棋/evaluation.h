#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define WIN5 100000
#define ALIVE4 10000
#define DIE4 1000
#define ALIVE3 1000
#define DIE3 100
#define ALIVE2 100
#define DIE2 10
#define ALIVE1 10
int count_empty_number(int n[],int chesscolour);
int score_table(int number,int empty);
int evaluation(int chesscolour); 
