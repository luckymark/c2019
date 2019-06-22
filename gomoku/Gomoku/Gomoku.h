/*
	Gomoku.h
	全局头文件,包括Public方法与常量
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//棋盘宽度
#define WIDTH 15
//玩家棋子
#define PLAYER '1'
//电脑棋子
#define COMPUTER '2'
//空
#define EMPTY '0'
//流局
#define DRAW '3'
#define INF 10000000
#define DEPTH 5
#define MAXCOUNT 5

struct Pos {
	int x;
	int y;
	int scores;
};

#pragma region AC
void AC_Init(char* (_paterns[]), int length);
int* AC_ACSearch(char str[], int* length);
#pragma endregion

#pragma region PossiblePositionManager
Pos* getPossiblePositions(int* count);
#pragma endregion

#pragma region Evaluate
void evaluateInit();
int getPositionScores(int x, int y);
int evaluate(int type);
int evaluateAll(int role);
void getStep(int x, int y, int* resultX, int* resultY);
void updateScores(int x, int y, int* scores1, int* scores2, int isBack);
#pragma endregion

#pragma region BoardManager
void setChessboard(int x, int y, char chessType);
char getChessboard(int x, int y);
void reloadGame();
void reloadWinner();
char getBoardStatus();
#pragma endregion

