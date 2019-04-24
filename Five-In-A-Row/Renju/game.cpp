#include <windows.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include "game.h"

const int WEIGHT[6] = {1, 2, 4, 8, 15, 16};
const int W_SUC[8] = {0, 8, 17, 65, 256, 512, 512, 1024};

int lowbit(int val)
{
    return val & -val;
}

int countBit(int val)
{
    int ret = 0;
    while (val)
    {
        val -= lowbit(val);
        ret++;
    }
    return ret;
}

int countPreSucBit(int val)
{
    int ret = 0;
    for (int i = 1; i <= val; i <<= 1)
    {
        if ((i & val) == 0) break;
        ret++;
    }
    return ret;
}

bool inRange(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

Game::Game()
{
    memset(board, 0, sizeof board);
    memset(status, 0, sizeof status);
    memset(score, 0, sizeof score);
    validateAll();
    curType = 1;
}

int Game::getChess(int x, int y)
{
    if (board[x + MG][y + MG][0]) return 2;
    if (board[x + MG][y + MG][1]) return 1;
    return 0;
}

int Game::rate(int x, int y, int dir, int type)
{
    int val = 0;
    for (int i = 0; i < 5; i++)
    {
        int px = x + MG + i * DX[dir];
        int py = y + MG + i * DY[dir];
        if (!inRange(px - MG, py - MG) || board[px][py][type^1])
        {
            status[x][y][dir][type] = val;
            return val;
        }
        val = (val << 1) + board[px][py][type];
    }
    val = (val<<1)+1;
    status[x][y][dir][type] = val;
    return val;
}

int Game::calcScore(int x, int y, int type)
{
    score[x][y][type] = 0;
    for (int i = 0; i < 4; i++)
    {
        int val = status[x][y][i][type];
        int valOpp = status[x][y][(i+4) % 8][type];
        score[x][y][type] += WEIGHT[countBit(val)] + WEIGHT[countBit(valOpp)];
        score[x][y][type] += W_SUC[countPreSucBit(val) + countPreSucBit(valOpp)];
        qDebug() << val << valOpp << endl;
    }
    return score[x][y][type];
}

void Game::validateAll()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                rate(i, j, k, 0);
                rate(i, j, k, 1);
            }
            calcScore(i, j, 0);
            calcScore(i, j, 1);
        }
    }
    /*for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; i < BOARD_SIZE; j++)
        {
            qDebug() << score[i][j][1] << ", " << score[i][j][0];
        }
        qDebug() << endl;
    }*/
}

void Game::placeChess()
{
    board[curX + MG][curY + MG][curType] = 1;
    qDebug() << curX << " " << curY << endl;

    /*for (int k = 0; k < 8; k++)
    {
        for (int d = 1; d < 5; d++)
        {
            int px = curX + d * DX[k];
            int py = curY + d * DY[k];
            if (px < 0 || px >= BOARD_SIZE) continue;
            if (py < 0 || py >= BOARD_SIZE) continue;
            if (getChess(px, py)) continue;
            rate(px, py, (k+4) % 8, 1);
            rate(px, py, (k+4) % 8, 0);
            calcScore(px, py, 1);
            calcScore(px, py, 0);
        }
    }*/

    validateAll();
    curType ^= 1;
}

int Game::validateWin()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (rate(i, j, k, 1) == 63)
                    return 1;
                if (rate(i, j, k, 0) == 63)
                    return 2;
            }
        }
    }
    return 0;
}

void Game::AIdecide()
{
    srand(time(nullptr));
    curX = curY = 0;

    int maxVal = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (getChess(i, j)) continue;
            if (score[i][j][curType] > maxVal)
            {
                curX = i;
                curY = j;
                maxVal = score[i][j][curType];
            }
            if (score[i][j][curType^1] > maxVal)
            {
                curX = i;
                curY = j;
                maxVal = score[i][j][curType^1];
            }
        }
    }
    if (maxVal == 0)
    {
        while (getChess(curX, curY))
        {
            curX = rand() % BOARD_SIZE;
            curY = rand() % BOARD_SIZE;
        }
    }
    placeChess();
}
