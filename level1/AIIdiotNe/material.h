
//#ifndef AIIDIOTNE_MATERIAL_H
//#define AIIDIOTNE_MATERIAL_H
//
//#endif //AIIDIOTNE_MATERIAL_H
#pragma once
#include "hlibrary.h"

typedef struct
{
    int x;
    int y;
}Pos;

typedef struct node
{
    struct node *next[CHESSTYPE];
    struct node *fail;
    bool end;
    int score;
}Node;

typedef struct
{
    Pos index;
    int score;
}ScoreCard;

typedef struct
{
    Pos *base;
    Pos *top;
    int stacksize;
}SqStack;