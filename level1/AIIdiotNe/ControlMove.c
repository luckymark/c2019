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

void SetChessColor(void)
{
    HANDLE chess;
    chess= GetStdHandle(STD_OUTPUT_HANDLE);
    if (gamer)
        SetConsoleTextAttribute(chess, CCHESSCOLOR+15*0x10);
    else
        SetConsoleTextAttribute(chess, PCHESSCOLOR+15*0x10);
}
/**
 * control the cursor position
 * @param x :x ordinate, but the definition about x in cmd and mine is opposite
 * so let pos.X=y
 * @param y :same as x.
 */
void GoToxy(int x, int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=y;
    pos.Y=x;
    SetConsoleCursorPosition(handle, pos);
}
/**
 * affine function is affine transformation from topology structure to cmd
 * @param  x [description]
 * @return   [description]
 */
int AffineX(int x)
{
    return 2*x+1;
}
int AffineY(int y)
{
    return 4*y;
}