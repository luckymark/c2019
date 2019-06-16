#include "board.h"
#include <cstring>
#include <QDebug>
#include <cmath>
#include <iostream>

int posAdd(int x, int y)
{
    return std::min(BOARD_SIZE/2-abs(BOARD_SIZE/2-x), BOARD_SIZE/2 - abs(BOARD_SIZE/2-y));
}

bool inRange(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

Board::Board()
{
    memset(chess, 0, sizeof chess);
    memset(status, 0, sizeof status);
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            score[i][j][0] = score[i][j][1] = posAdd(i, j);
}

int Board::getChess(int x, int y)
{
    return chess[x][y];
}

int Board::putChess(int x, int y, int type)
{
    if (getChess(x, y)) return 0;
    chess[x][y] = type;
}

int Board::checkWin()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (status[i][j][k] == 22222) return RED_CHESS;
                if (status[i][j][k] == 11111) return WHITE_CHESS;
            }
        }
    }
    return 0;
}

int Board::getChessStatus(int x, int y, int dir)
{
    int cur = 0;
    for (int i = 5; i >= 1; i--)
    {
        int px = x + i * DX[dir];
        int py = y + i * DY[dir];
        if (inRange(px, py)) cur = cur*10 + chess[px][py];
        else cur = cur*10 + 3;
    }
    status[x][y][dir] = cur;
    return cur;
}

void Board::getAllStatus()
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            for (int k = 0; k < BOARD_SIZE; k++)
                getChessStatus(i, j, k);
}

int Board::calcScoreRed(int x, int y)
{
    int cur = 0;
    for (int i = 0; i < 8; i++)
    {
        int st = status[x][y][i];
        if (st == 22222)
            cur += LIVE_5;
        else if (st == 2222)
            cur += LIVE_4;
        else if (st == 32222 || st == 12222)
            cur += SLEEP_4;
        else if (st % 10000 == 222)
            cur += LIVE_3;
        else if (st == 32220 || st == 12220 || st == 3222 || st == 1222)
            cur += SLEEP_3;
        else if (st % 10000 == 22 || st == 220 || st % 10000 == 202)
            cur += LIVE_2;
        else if (st % 1000 == 122 || st % 1000 == 322 || st % 10000 == 1220 || st % 10000 == 3220 ||
                 st == 12200 || st == 32200 || st == 12020 || st == 32020)
            cur += SLEEP_2;
        else if (st == 12002 || st == 32002 || st == 20002)
            cur += SLEEP_2;
        else if (st % 10000 == 2 || st % 10000 == 20 || st % 10000 == 200 || st % 10000 == 2000)
            cur += LIVE_1;
    }
    score[x][y][1] = cur + posAdd(x, y);
    return cur;
}

int Board::calcScoreWhite(int x, int y)
{
    int cur = 0;
    for (int i = 0; i < 8; i++)
    {
        int st = status[x][y][i];
        if (st == 11111)
            cur += LIVE_5;
        else if (st == 1111)
            cur += LIVE_4;
        else if (st == 31111 || st == 21111)
            cur += SLEEP_4;
        else if (st % 10000 == 111)
            cur += LIVE_3;
        else if (st == 31110 || st == 21110 || st == 3111 || st == 2111)
            cur += SLEEP_3;
        else if (st % 10000 == 11 || st == 110 || st % 10000 == 101)
            cur += LIVE_2;
        else if (st % 1000 == 211 || st % 1000 == 311 || st % 10000 == 2110 || st % 10000 == 3110 ||
                 st == 21100 || st == 31100 || st == 21010 || st == 31010)
            cur += SLEEP_2;
        else if (st == 21001 || st == 31001 || st == 10001)
            cur += SLEEP_2;
        else if (st % 10000 == 1 || st % 10000 == 10 || st % 10000 == 100 || st % 10000 == 1000)
            cur += LIVE_1;
    }
    score[x][y][0] = cur + posAdd(x, y);
    return cur;
}

void Board::validateAllScore()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            calcScoreRed(i, j);
            calcScoreWhite(i, j);
        }
    }
}
