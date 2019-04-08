#include "maze.h"

int move(char map[][Length], struct Location *loc1, int X, int Y)
{
    int flag;
    switch (map[Y][X])
    {
    case 3:
        flag = 0;
        break;
    case 0:
        flag = 1;
        break;

    default:
        return 1;
    }
    map[loc1->Y][loc1->X] = 0;
    loc1->X = X;
    loc1->Y = Y;
    map[loc1->Y][loc1->X] = 2;
    printmap(map);
    return flag;
}