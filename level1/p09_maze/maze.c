//Reopen with GB2312
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define HEIGHT 25
#define WIDTH 25
#define true 1
#define false 0
int **xoy;
int checkVictory(int x, int y);
int show();
int findWay(int x, int y);
int checkCanGo(int x, int y, int d);
int setPoint(int x, int y, int type);
int main()
{
    int i, e;
    xoy = (int **)malloc(sizeof(int *) * WIDTH);
    for (i = 0; i < WIDTH; i++)
    {
        xoy[i] = (int *)malloc(sizeof(int) * HEIGHT);
        for (e = 0; e < HEIGHT; e++)
        {
            xoy[i][e] = 0;
        }
    }
    time_t t;
    srand((unsigned)time(&t));
    findWay(0, 1);
    setPoint(0, 1, 2);
    setPoint(WIDTH - 2, HEIGHT - 1, 1);
    setPoint(WIDTH - 2, HEIGHT - 2, 1);
    show();
    char c;
    int lastX = 0, lastY = 1;
    while ((c = getch()) != '\n')
    {
        if ((c == 'w' || c == 'W') && lastY - 1 >= 0 && (xoy[lastX][lastY - 1] == 1))
        {
            if (checkVictory(lastX, lastY - 1))
                break;
            setPoint(lastX, lastY, 1);
            lastY--;
            setPoint(lastX, lastY, 2);
            show();
        }
        else if ((c == 's' || c == 'S') && lastY + 1 <= HEIGHT && xoy[lastX][lastY + 1] == 1)
        {
            if (checkVictory(lastX, lastY + 1))
                break;
            setPoint(lastX, lastY, 1);
            lastY++;
            setPoint(lastX, lastY, 2);
            show();
        }
        else if ((c == 'a' || c == 'A') && lastX - 1 >= 0 && xoy[lastX - 1][lastY] == 1)
        {
            if (checkVictory(lastX - 1, lastY))
                break;
            setPoint(lastX, lastY, 1);
            lastX--;
            setPoint(lastX, lastY, 2);
            show();
        }
        else if ((c == 'd' || c == 'D') && lastY + 1 <= WIDTH && xoy[lastX + 1][lastY] == 1)
        {
            if (checkVictory(lastX + 1, lastY))
                break;
            setPoint(lastX, lastY, 1);
            lastX++;
            setPoint(lastX, lastY, 2);
            show();
        }
    }
    system("cls");
    printf("恭喜你成功通关！按任意键退出");
    getch();
    return 0;
}
int checkVictory(int x, int y)
{
    if (x == WIDTH - 2 && y == HEIGHT - 1)
    {
        return true;
    }
    return false;
}
int show()
{
    system("cls");
    int e, i;
    for (e = 0; e < HEIGHT; e++)
    {
        for (i = 0; i < WIDTH; i++)
        {
            printf(xoy[i][e] == 0 ? "■" : xoy[i][e] == 2 ? "●" : xoy[i][e] == 3 ? "★" : "  ");
        }
        printf("\n");
    }
    printf("使用WASD移动");
    return true;
}
int findWay(int x, int y)
{
    int d;
    int dtemp[4] = {0, 0, 0, 0}, t = 0;
    do
    {
        d = rand() % 40 / 10;
        if (dtemp[d] == 1 && t < 4)
        {
            continue;
        }
        else if (t >= 4)
        {
            break;
        }
        dtemp[d] = 1;
        t++;
        if (checkCanGo(x, y, d))
        {
            d == 0 ? --y : d == 1 ? y++ : d == 2 ? --x : x++;
            setPoint(x, y, 1);
            if (findWay(x, y))
            {
                return true;
            }
            else
            {
                d == 0 ? ++y : d == 1 ? y-- : d == 2 ? ++x : x--;
                continue;
            }
        }
    } while (true);
    return false;
}
int checkCanGo(int x, int y, int d)
{
    d == 0 ? --y : d == 1 ? y++ : d == 2 ? --x : x++;
    if (x >= WIDTH - 1 || y >= HEIGHT - 1 || x <= 0 || y <= 0)
    {
        return false;
    }
    if (xoy[x][y] == 1)
    {
        return false;
    }
    if (d == 0 && xoy[x + 1][y] == 0 && xoy[x - 1][y] == 0 && xoy[x][y - 1] == 0)
    {
        return true;
    }
    if (d == 1 && xoy[x + 1][y] == 0 && xoy[x - 1][y] == 0 && xoy[x][y + 1] == 0)
    {
        return true;
    }
    if (d == 2 && xoy[x][y + 1] == 0 && xoy[x - 1][y] == 0 && xoy[x][y - 1] == 0)
    {
        return true;
    }
    if (d == 3 && xoy[x + 1][y] == 0 && xoy[x][y - 1] == 0 && xoy[x][y - 1] == 0)
    {
        return true;
    }
    return false;
}
int setPoint(int x, int y, int type)
{
    xoy[x][y] = type;
}