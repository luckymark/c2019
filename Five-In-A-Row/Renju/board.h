#ifndef BOARD_H
#define BOARD_H
#include "scorelist.h"

const int DX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int DY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int BOARD_SIZE = 15;
const int WHITE_CHESS = 1;
const int RED_CHESS = 2;

struct Board
{
    Board();
    int chess[BOARD_SIZE][BOARD_SIZE];
    int status[BOARD_SIZE][BOARD_SIZE][8];
    int score[BOARD_SIZE][BOARD_SIZE][2];
    int checkWin();
    int getChess(int x, int y);
    int putChess(int x, int y, int type);
    int getChessStatus(int x, int y, int dir);
    void getAllStatus();
    int calcScoreRed(int x, int y);
    int calcScoreWhite(int x, int y);
    void validateAllScore();
};

#endif // BOARD_H
