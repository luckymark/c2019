#ifndef GAME_H
#define GAME_H
#include "point.h"
#include "board.h"
#include "alphabeta.h"

struct Game
{
    Game();
    ~Game();
    int curType;
    int curX, curY;
    Board *bd;
    int checkWin();
    void nextMove();
    void AIdecide();
    void switchType();
};

#endif // GAME_H
