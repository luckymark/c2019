#include "maze.h"

void printmap(char map[Height][Length])
{
    system("cls");
    for (size_t i = 0; i < Height; i++)
    {
        for (size_t t = 0; t < Length; t++)
        {
            switch (map[i][t])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("¨€");
                break;
            case 2:
                printf("@ ");
                break;
            case 3:
                printf("¡ù");
                break;

            default:
                break;
            };
        }
        printf("\n");
    }
    printf("\nUse 'W','S','A','D' to move around.");
}