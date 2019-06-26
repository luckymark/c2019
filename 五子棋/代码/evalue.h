#ifndef TEST2_EVALUE_H
#define TEST2_EVALUE_H

#endif //TEST2_EVALUE_H

#include "test2.h"

#define LEVEL0 1500000
#define LEVEL1 720000
#define LEVEL2 300000
#define LEVEL31 5500
#define LEVEL32 5000
#define LEVEL33 4200
#define LEVEL34 4000
#define LEVEL41 650
#define LEVEL42 600
#define LEVEL43 550
#define LEVEL44 500
#define LEVEL51 250
#define LEVEL52 200
#define LEVEL53 150
#define LEVEL6 20

int is_level_1(int *p, int turn);
int is_level_2(int *p, int turn);
int is_level_3(int *p, int turn);
int is_level_4(int *p, int turn);
int is_level_5(int *p, int turn);
int is_level_6(int *p, int turn);
int getvalue(int *p, int turn, DPT *head);
BOOL match(int *sample, int n, int *text);
