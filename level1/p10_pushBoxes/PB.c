#include "PB.h"

int main(int argc, char const *argv[])
{
    int flag = 1;
    struct Location loc1 = {3, 3}, loc2 = {1, 3};
    char map[Height][Length] =
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 3, 1},
            {1, 0, 4, 1, 1},
            {1, 0, 0, 2, 1},
            {1, 1, 1, 1, 1}};

    flag = move(map, &loc1, loc1.X, loc1.Y, &loc2);
    while (flag)
    {
        switch (getch())
        {
        case 'w':
            flag = move(map, &loc1, loc1.X, loc1.Y - 1, &loc2);
            break;
        case 's':
            flag = move(map, &loc1, loc1.X, loc1.Y + 1, &loc2);
            break;
        case 'a':
            flag = move(map, &loc1, loc1.X - 1, loc1.Y, &loc2);
            break;
        case 'd':
            flag = move(map, &loc1, loc1.X + 1, loc1.Y, &loc2);
            break;

        default:
            break;
        }
    }
    printf("\nCongratulations");
    system("pause");
    return 0;
}
