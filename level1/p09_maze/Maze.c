#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUM_PATH 0
#define NUM_WALL 1
#define NUM_PLAYER 2
#define NUM_EXIT 4

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

#define MAP_MAX_SIZE 50

const char* BANNER_PATH = "banner.txt";

const char* SYMBLE_PATH = "  ";
const char* SYMBLE_WALL = "▓";
const char* SYMBLE_PLAYER = "●";
const char* SYMBLE_EXIT = "★";

const int DIR_ARR[2][4] = {
    {0, 0, -1, 1},  // x
    {-1, 1, 0, 0}   // y
};

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
int rows, cols;
int startX, startY;
int endX, endY;
int playerWin = 0;
int playerX, playerY;

void consoleInit();
void gotoxy(short x, short y);
void startGame(const char* mapFile);
void initMap(const char* mapFile);
void printMap();
void listenKey();
void movePlayer(int dir);
void checkWin();
void endGame();

int main() {
    consoleInit();
    startGame("map.txt");

    printf("\n");
    system("pause");
    return 0;
}

void consoleInit() {
    system("color 2");
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(short x, short y) {  // 设置光标位置，用于局部刷新，解决闪烁问题
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void printMap() {
    system("cls");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            switch (map[i][j]) {
                case NUM_PATH:
                    printf("%s", SYMBLE_PATH);
                    break;
                case NUM_WALL:
                    printf("%s", SYMBLE_WALL);
                    break;
                case NUM_PLAYER:
                    printf("%s", SYMBLE_PLAYER);
                    break;
                case NUM_EXIT:
                    printf("%s", SYMBLE_EXIT);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void initMap(const char* mapFile) {
    FILE* fp;
    if ((fp = fopen(mapFile, "r")) == NULL) {
        printf("error!");
        return;
    }
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            fscanf(fp, "%d", &map[i][j]);
            if (map[i][j] == NUM_PLAYER) {
                playerX = startX = j;
                playerY = startY = i;
            } else if (map[i][j] == NUM_EXIT) {
                endX = j;
                endY = i;
            }
        }
    }
    fclose(fp);
    // border
    for (int i = 0; i < rows + 2; i++) {
        map[i][0] = 1;
        map[i][cols + 1] = 1;
    }
    for (int i = 0; i < cols + 2; i++) {
        map[0][i] = 1;
        map[rows + 1][i] = 1;
    }
}

void checkWin() {
    if (playerX == endX && playerY == endY) playerWin = 1;
}

void movePlayer(int dir) {
    if (map[playerY + DIR_ARR[1][dir]][playerX + DIR_ARR[0][dir]] != NUM_WALL) {
        map[playerY][playerX] = NUM_PATH;
        gotoxy(2 * playerX - 2, playerY - 1);
        printf("%s", SYMBLE_PATH);
        playerY += DIR_ARR[1][dir];
        playerX += DIR_ARR[0][dir];
        map[playerY][playerX] = NUM_PLAYER;
        gotoxy(2 * playerX - 2, playerY - 1);
        printf("%s", SYMBLE_PLAYER);
        checkWin();
    }
}

void listenKey() {
    char key;
    while (!playerWin) {
        key = getch();
        switch (key) {
            case 119:
                movePlayer(DIR_UP);
                break;
            case 115:
                movePlayer(DIR_DOWN);
                break;
            case 97:
                movePlayer(DIR_LEFT);
                break;
            case 100:
                movePlayer(DIR_RIGHT);
                break;
            default:
                break;
        }
    }
}

void endGame() {
    system("cls");
    FILE* fp;
    char strLine[1024];
    if ((fp = fopen(BANNER_PATH, "r")) == NULL) {
        printf("error!");
        return;
    }
    while (!feof(fp)) {
        fgets(strLine, 1024, fp);
        printf("%s", strLine);
    }
    fclose(fp);
}

void startGame(const char* mapFile) {
    initMap(mapFile);
    printMap();
    listenKey();
    endGame();
}
