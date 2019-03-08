//Reopen with GB2312
//就编了3个关卡......
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define HEIGHT 10
#define WIDTH 10
#define TOTAL_LEVEL 3
#define TOTAL_SPOT 3
#define true 1
#define false 0
struct Level
{
    int index;
    int step;
};

struct Config
{
    int nowLevel;
    Level *levels;
};
int checkCanGo(int x, int y, int d, int **xoy);
void move(int *x, int *y, int d, int *spot, int **xoy);
int show(int level, int step);
Config *getConfig();
void saveConfig(Config *config);
int **readMapFromFile(int level);
int show(int level, int step, int **xoy);
int setPoint(int x, int y, int type, int **xoy);
int main()
{
    Config *config = getConfig();
    while (true)
    {
        if (config->nowLevel == TOTAL_LEVEL)
        {
            system("cls");
            printf("恭喜你已经通关全部关卡，继续游戏请按下回车键（此操作将会清除之前的记录），否则请按任意非回车键关闭\n");
            char c = getch();
            if (c != 13)
                break;

            config->nowLevel = 0;
        }
        int **xoy = readMapFromFile(config->nowLevel + 1);
        int step = 0, level = config->nowLevel + 1;
        char c;
        int restart = false, lastX = 0, lastY = 0, spot = 0;
        show(level, step, xoy);
        setPoint(lastX, lastY, 2, xoy);
        while (true)
        {
            c = getch();
            if ((c == 'w' || c == 'W') && checkCanGo(lastX, lastY, 0, xoy))
            {
                step++;
                move(&lastX, &lastY, 0, &spot, xoy);
                show(level, step, xoy);
            }
            else if ((c == 's' || c == 'S') && checkCanGo(lastX, lastY, 1, xoy))
            {
                step++;
                move(&lastX, &lastY, 1, &spot, xoy);
                show(level, step, xoy);
            }
            else if ((c == 'a' || c == 'A') && checkCanGo(lastX, lastY, 2, xoy))
            {
                step++;
                move(&lastX, &lastY, 2, &spot, xoy);
                show(level, step, xoy);
            }
            else if ((c == 'd' || c == 'D') && checkCanGo(lastX, lastY, 3, xoy))
            {
                step++;
                move(&lastX, &lastY, 3, &spot, xoy);
                show(level, step, xoy);
            }
            else if ((c == 'g' || c == 'G'))
            {
                saveConfig(config);
            }
            else if ((c == 'r' || c == 'R'))
            {
                restart = true;
                break;
            }
            if (spot == TOTAL_SPOT)
                break;
        }
        if (!restart)
        {
            config->levels[config->nowLevel].index = config->nowLevel;
            config->levels[config->nowLevel].step = step;
            config->nowLevel++;
            saveConfig(config);
            system("cls");
            printf("恭喜你成功通关！按任意键进入下一关...\n");
            free(xoy);
            getch();
        }
    }
    return 0;
}
int checkCanGo(int x, int y, int d, int **xoy)
{
    int willX = x, willY = y;
    d == 0 ? willY-- : d == 1 ? willY++ : d == 2 ? willX-- : willX++;
    int boxX = willX * 2 - x, boxY = willY * 2 - y;

    if (willY > HEIGHT - 1 || willX > WIDTH - 1 || willX < 0 || willY < 0)
    {
        return false;
    }
    if (xoy[willX][willY] == 0 || xoy[willX][willY] == 5 || xoy[willX][willY] == 4)
    {
        return false;
    }
    if (xoy[willX][willY] == 3 && (boxX < 0 || boxX > WIDTH - 1 || boxY < 0 || boxY > HEIGHT - 1 || xoy[boxX][boxY] == 0 || xoy[boxX][boxY] == 3 || xoy[boxX][boxY] == 5))
    {
        return false;
    }
    return true;
}
void move(int *x, int *y, int d, int *spot, int **xoy)
{
    int willX = *x, willY = *y;
    d == 0 ? willY-- : d == 1 ? willY++ : d == 2 ? willX-- : willX++;
    int boxX = willX * 2 - *x, boxY = willY * 2 - (*y);
    if (xoy[willX][willY] == 3)
    {
        if (xoy[boxX][boxY] == 4)
        {
            setPoint(boxX, boxY, 5, xoy);
            (*spot)++;
        }
        else
        {
            setPoint(boxX, boxY, 3, xoy);
        }
    }
    setPoint(*x, *y, 1, xoy);
    *x = willX;
    *y = willY;
    setPoint(willX, willY, 2, xoy);
}
Config *getConfig()
{
    char length_[20];
    FILE *f;
    int level, i;
    f = fopen("config.ini", "rb");
    fscanf(f, "LEVEL:%s", length_);
    level = atoi(length_);
    Config *config = (Config *)malloc(sizeof(Config));
    config->nowLevel = level;
    config->levels = (Level *)malloc(sizeof(Level) * TOTAL_LEVEL);
    for (i = 0; i < level; i++)
    {
        fscanf(f, "Step:%s", length_);
        Level l;
        l.index = i + 1;
        l.step = atoi(length_);
        config->levels[i] = l;
    }
    fclose(f);
    return config;
}
void saveConfig(Config *config)
{
    FILE *f;
    int i;

    f = fopen("config.ini", "w+");
    fprintf(f, "LEVEL:%d\n", config->nowLevel);
    for (i = 0; i < config->nowLevel; i++)
    {
        fprintf(f, "Step:%d\n", config->levels[i].step);
    }
    fclose(f);
}
int **readMapFromFile(int level)
{
    FILE *f;
    char p[] = "level\\";
    char temp[8];
    itoa(level, temp, 10);
    char *path = strcat(p, temp);
    int **xoy;
    int e, i;
    xoy = (int **)malloc(sizeof(int *) * WIDTH);
    for (i = 0; i < 10; i++)
    {
        xoy[i] = (int *)malloc(sizeof(int) * HEIGHT);
    }
    f = fopen(path, "rb");
    for (i = 0; i < 10; i++)
    {
        for (e = 0; e < 10; e++)
        {
            fscanf(f, "%d", &xoy[e][i]);
        }
    }
    fclose(f);
    return xoy;
}
int show(int level, int step, int **xoy)
{
    system("cls");
    int e, i;
    for (e = 0; e < HEIGHT; e++)
    {
        for (i = 0; i < WIDTH; i++)
        {
            printf(xoy[i][e] == 0 ? "■" : xoy[i][e] == 2 ? "●" : xoy[i][e] == 3 ? "◎" : xoy[i][e] == 4 ? "◇" : xoy[i][e] == 5 ? "◆" : "  ");
        }
        switch (e)
        {
        case 0:
            printf("      [LEVEL%d]", level);
            break;
        case 1:
            printf("      [STEP:%d]", step);
            break;
        case 2:
            printf("      [●]你");
            break;
        case 3:
            printf("      [■]墙");
            break;
        case 4:
            printf("      [◇]目的地");
            break;
        case 5:
            printf("      [◎]箱子");
            break;
        case 6:
            printf("      [◆]到达目标的箱子");
            break;
        case 8:
            printf("      [W A S D 移动]");
            break;
        case 9:
            printf("      [S 保存 R 重置]");
            break;
        default:
            break;
        }
        printf("\n");
    }
    return true;
}
int setPoint(int x, int y, int type, int **xoy)
{
    xoy[x][y] = type;
}