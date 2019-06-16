#include <windows.h>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include "game.h"
#include "alphabeta.h"

Game::Game()
{
    bd = new Board();
    curType = RED_CHESS;
}

Game::~Game()
{
    delete bd;
}

void Game::nextMove()
{
    if (curType == RED_CHESS)
    {
        bd->putChess(curX, curY, curType);
    }
    else
    {
        AIdecide();
    }
    //bd->putChess(curX, curY, curType);
    switchType();
    bd->getAllStatus();
    bd->validateAllScore();
}

void Game::AIdecide()
{
    AlphaBeta *ai = new AlphaBeta();
    ai->getInBoardStatus(this->bd);
    //ai->alphaBetaSearch(bd, 1, 2, INF, -INF);
    Point bestPos;
    int maxPoint = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (!bd->getChess(i, j))
            {
                if (bd->score[i][j][0] > maxPoint)
                {
                    bestPos.set(i, j);
                    maxPoint = bd->score[i][j][0];
                }
                if (bd->score[i][j][1] > maxPoint)
                {
                    bestPos.set(i, j);
                    maxPoint = bd->score[i][j][1];
                }
            }
    bd->putChess(bestPos.x, bestPos.y, WHITE_CHESS);
}

int Game::checkWin()
{
    return bd->checkWin();
}

void Game::switchType()
{
    if (curType == RED_CHESS) curType = WHITE_CHESS;
    else curType = RED_CHESS;
}
