#ifndef GAME_H
#define GAME_H

const int BOARD_SIZE = 15;
const int MG = 4;
const int DX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int DY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class Game
{
public:
    Game();
    int curType;
    int curX, curY;
    int board[BOARD_SIZE + MG * 2][BOARD_SIZE + MG * 2][2];
    int status[BOARD_SIZE][BOARD_SIZE][8][2];
    int score[BOARD_SIZE][BOARD_SIZE][2];
    int getChess(int x, int y);
    int rate(int x, int y, int dir, int type);
    int calcScore(int x, int y, int type);
    void validateAll();
    void placeChess();
    int validateWin();
    void AIdecide();
};

#endif // GAME_H
