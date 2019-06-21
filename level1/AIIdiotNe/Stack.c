//
// Created by Newton on 2019/6/19.
//
#include "FIR.h"

extern char PatternTable[PATTERNNUM][7];
extern char PatternTable1[PATTERNNUM][7];
extern int ValueTable[PATTERNNUM];

extern Node *root;
extern Node *root1;
extern Node *Q[MAXLTH];
extern Node *Q1[MAXLTH];

extern bool gamer;
extern bool Victory;

extern char chessboard[WIDTH][WIDTH];

bool InitStack(SqStack *S)
{
    S->base=(Pos*)malloc(STACK_INIT_SIZE * sizeof(Pos));
    /*if (!S->base)
        exit(OVERFLOW);*/
    S->top= S->base;
    S->stacksize= STACK_INIT_SIZE;
    return true;
}
void Push(SqStack *S, Pos *move)
{
    /*if (S->top - S->base >= S.stacksize){
        S->base=(Pos*)realloc(S->base,
            (S->stacksize+STACKINCREMENT)*sizeof(Pos));
        if (S->base)
            exit(OVERFLOW);
        S->top= S->base + S->stacksize;
        S->stacksize+= STACKINCREMENT;
    }*/

    *S->top++= *move;
}
bool Pop(SqStack *S, Pos *move)
{
    if (S->top== S->base)
        return false;

    *move= *--S->top;
    return true;
}
