#ifndef ALPHABETA_H
#define ALPHABETA_H
#include "point.h"
#include "board.h"
const int INF = 0x6fffffff;

struct AlphaBeta
{
    AlphaBeta();
    Board *bd;
    Point bestPos;
    void updateBestStatus();
    void getInBoardStatus(Board *inputBoard);
    void alphaBetaSearch(Board *curBd, int depth, int alpha, int beta);
};

#endif // ALPHABETA_H
