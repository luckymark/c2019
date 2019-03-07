#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUM_PATH 0
#define NUM_WALL 1
#define NUM_PLAYER 2
#define NUM_BOX 3
#define NUM_HOLDER 4

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

#define MAP_MAX_SIZE 50
#define HOLDER_MAX_SIZE 10

const char* BANNER_PATH = "banner.txt";
const char* MAP_PATH = "map.txt";

const char* SYMBLE_PATH = "  ";
const char* SYMBLE_WALL = "▓";
const char* SYMBLE_PLAYER = "●";
const char* SYMBLE_BOX = "■";
const char* SYMBLE_HOLDER = "★";

const int DIR_ARR[2][4] = {
    {0, 0, -1, 1},  // x
    {-1, 1, 0, 0}   // y
};

int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
int levels; // 总关数
int currLevel = 0;
int rows, cols;
int currBoxes = 0; 
// store the positions of holders
int holders[2][HOLDER_MAX_SIZE];
int startX, startY;
int endX, endY;
int playerX, playerY;
int playerWin = 0;
int holderSize = 0;
long fileReadPosition = 0L;


void consoleInit() {
    system("color 2");
    // system("mode con cols=60 lines=30");
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
                case NUM_HOLDER:
                    printf("%s", SYMBLE_HOLDER);
                    break;
                case NUM_BOX:
                    printf("%s", SYMBLE_BOX);
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void resetHolders() {
    for(int i = 0; i < holderSize; i++) {
        if(map[holders[1][i]][holders[0][i]] == NUM_PATH){
            map[holders[1][i]][holders[0][i]] = NUM_HOLDER;
            gotoxy(2 * holders[0][i], holders[1][i]);
            printf("%s", SYMBLE_HOLDER);
        }
    }
}

void initMap() {
    FILE* fp;
    holderSize = 0;
    // 用r模式读取获取文件当前读取位置会出错
    if ((fp = fopen(MAP_PATH, "rb")) == NULL) {
        printf("error!");
        return;
    }
    fseek(fp, fileReadPosition, SEEK_SET);
    // 初始化关卡数
    if(fileReadPosition == 0) fscanf(fp, "%d", &levels);
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &map[i][j]);
            if (map[i][j] == NUM_PLAYER) {
                playerX = startX = j;
                playerY = startY = i;
            }else if(map[i][j] == NUM_HOLDER){
                holders[0][holderSize] = j; // x
                holders[1][holderSize] = i; // y
                holderSize++;
            }
        }
    }
    fileReadPosition = ftell(fp);
    fclose(fp);
    printMap();
}

int checkWin() {
    for(int i = 0; i < holderSize; i++) {
        if(map[holders[1][i]][holders[0][i]] != NUM_BOX) {
            return 0;
        }
    }
    return 1;
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
    system("pause");
}

void showMenu() {
    if(currLevel >= levels) {
        endGame();
        return;
    }
    system("cls");
    printf("You've passed level%d\n", currLevel);
    printf("[n]: Press n to continue\n");
    printf("[q]: Press q to quit\n");
    char c;
    while((c = getch()) != 'n' && c != 'q');
    if(c == 'n') {
        initMap();
    }else{
        exit(1);
    }
}

void movePlayer(int dir) {
    int t;
    if ((t = map[playerY + DIR_ARR[1][dir]][playerX + DIR_ARR[0][dir]]) == NUM_PATH || t == NUM_HOLDER) {
        map[playerY][playerX] = NUM_PATH;
        gotoxy(2 * playerX, playerY);
        printf("%s", SYMBLE_PATH);
        playerY += DIR_ARR[1][dir];
        playerX += DIR_ARR[0][dir];
        map[playerY][playerX] = NUM_PLAYER;
        gotoxy(2 * playerX, playerY);
        printf("%s", SYMBLE_PLAYER);
    } else if (map[playerY + DIR_ARR[1][dir]][playerX + DIR_ARR[0][dir]] == NUM_BOX) {
        if ((t = map[playerY + 2 * DIR_ARR[1][dir]][playerX + 2 * DIR_ARR[0][dir]]) == NUM_PATH || t == NUM_HOLDER) {
            map[playerY + 2 * DIR_ARR[1][dir]][playerX + 2 * DIR_ARR[0][dir]] =NUM_BOX;
            gotoxy(2 * (playerX + 2 * DIR_ARR[0][dir]), playerY + 2 * DIR_ARR[1][dir]);
            printf("%s", SYMBLE_BOX);
            map[playerY][playerX] = NUM_PATH;
            gotoxy(2 * playerX, playerY);
            printf("%s", SYMBLE_PATH);
            playerY += DIR_ARR[1][dir];
            playerX += DIR_ARR[0][dir];
            map[playerY][playerX] = NUM_PLAYER;
            gotoxy(2 * playerX, playerY);
            printf("%s", SYMBLE_PLAYER);
            if(t == NUM_HOLDER) {
                if(checkWin()) {
                    ++currLevel;
                    showMenu();
                }
            }
        } 
    }
    // 有可能box被推到holder上又被推走(或者player从holder上经过)，需要重新打印holder
    resetHolders();
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


void startGame() {
    initMap();
    listenKey();
}

int main() {
    consoleInit();
    startGame();

    printf("\n");
    system("pause");
    return 0;
}
