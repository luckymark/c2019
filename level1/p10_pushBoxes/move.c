#include "PB.h"

int move(char map[][Length], struct Location *loc1, int X, int Y, struct Location *loc2)
{
    if (map[Y][X] == 3) //人走到目标上
    {
        map[loc1->Y][loc1->X] = 0;
        loc1->X = X;
        loc1->Y = Y;
        loc2->X = X;
        loc2->Y = Y;
        map[loc1->Y][loc1->X] = 2;
    }

    if (map[Y][X] == 0 || map[Y][X] == 2) //人走到空地上
    {
        map[loc1->Y][loc1->X] = 0;
        loc1->X = X;
        loc1->Y = Y;
        map[loc2->Y][loc2->X] = 3;
        map[loc1->Y][loc1->X] = 2;
        printmap(map);
        return 1;
    }

    int dY = 2 * Y - loc1->Y, dX = 2 * X - loc1->X;
    if (map[Y][X] == 4 && map[dY][dX] == 0) //人走到箱子上且箱子前面是空地
    {
        map[loc1->Y][loc1->X] = 0;
        map[dY][dX] = 4;
        loc1->X = X;
        loc1->Y = Y;
        map[loc2->Y][loc2->X] = 3;
        map[loc1->Y][loc1->X] = 2;
        printmap(map);
        return 1;
    }
    if (map[Y][X] == 4 && map[dY][dX] == 3) //人走到箱子上且箱子前面是目标
    {
        map[loc1->Y][loc1->X] = 0;
        map[loc2->Y][loc2->X] = 3;
        map[dY][dX] = 4;
        loc1->X = X;
        loc1->Y = Y;
        map[loc1->Y][loc1->X] = 2;
        printmap(map);
        return 0;
    }
}