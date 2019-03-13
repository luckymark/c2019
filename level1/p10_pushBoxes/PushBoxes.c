#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>

#define NUM_PATH 0
#define NUM_WALL 1
#define NUM_PLAYER 2
#define NUM_BOX 3
#define NUM_HOLDER 4
#define NUM_BOX_HOLDER 5
#define NUM_PLAYER_HOLDER 6

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

#define MAP_MAX_SIZE 24
#define HOLDER_MAX_SIZE 10
#define LEVEL_MAX_SIZE 10

const char* BANNER_PATH = "banner.txt"; // 恭喜
const char* MAP_PATH = "map.dat"; // 地图
const char* RECORD_PATH = "record.dat"; // 记录
const char* SCORE_PATH = "score.dat"; // 分数

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
int records[LEVEL_MAX_SIZE];
int playerX, playerY;
int supposedMoves = 0;
int currMoves = 0;
int score = 0;
int playerWin = 0;
int holderSize = 0;
long fileReadPosition = 0L;
long preFileReadPosition = 0L;

void consoleInit();
void gotoxy(short x, short y);
int caclScore(int a, int b);
int containedInHolders(int x, int y);
bool checkWin();
void startGame();
void initMap();
void readRecords();
void dumpRecords();
void dumpScore();
void printMap();
void printInfo();
void printHolders();
void listenKey();
void movePlayer(int dir);
void showMenu();
void endGame();

int main() {
    consoleInit();
    startGame();

    printf("\n");
    system("pause");
    return 0;
}

void consoleInit() {
    system("color 2");
    system("mode con cols=40 lines=20");
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(short x, short y) {  // 设置光标位置，用于局部刷新，解决闪烁问题
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void readRecords() {
    FILE * fp;
    if((fp = fopen(RECORD_PATH, "r")) == NULL) {
        printf("error!");
        return;
    }
    // levels should be init first in initMap()
    for(int i = 0; i < levels; i++) {
        fscanf(fp, "%d", &records[i]);
    }
    fclose(fp);
}

void dumpRecords() {
    FILE * fp;
    if((fp = fopen(RECORD_PATH, "w+")) == NULL) {
        printf("error!");
        return;
    }
    for(int i = 0; i < levels; i++) {
        fprintf(fp, "%d ", records[i]);
    }
    fclose(fp);
}

void dumpScore() {
    FILE * fp;
    if((fp = fopen(SCORE_PATH, "a+")) == NULL){
        printf("error!");
        return;
    }
    fprintf(fp, "level%d: %d\n", currLevel, score);
    fclose(fp);
}

int caclScore(int a, int b) {
    if(b >= 2 * a) return 0;
    if(b <= a) return 100;
    double ta = a;
    double tb = b;
    return round((2 * ta - tb) / ta * 100);
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

void printInfo() {
    gotoxy(0, rows + 1);
    printf("current level: %d / %d\n",currLevel + 1, levels);
    printf("supposed moves: %d\n", supposedMoves);
    printf("current moves: %d\n", currMoves);
    printf("record: %d\n", records[currLevel]);
    printf("current score:%3d\n", score = caclScore(supposedMoves, currMoves));
    printf("press [r] to restart this level");
}

void printHolders() {
    for(int i = 0; i < holderSize; i++) {
        // holder上没有box或player则显示holder
        if(map[holders[1][i]][holders[0][i]] == NUM_PATH){
            gotoxy(2 * holders[0][i], holders[1][i]);
            printf("%s", SYMBLE_HOLDER);
        }
    }
}

// 如果需要检测的坐标为holder坐标就返回1
int containedInHolders(int x, int y) {
    for (int i = 0 ; i < holderSize; i++) {
        if(holders[0][i] == x && holders[1][i] == y) return 1;
    }
    return 0;
}

void initMap() {
    FILE* fp;
    // reset
    holderSize = 0;
    currMoves = 0;
    // 用r模式读取获取文件当前读取位置会出错
    if ((fp = fopen(MAP_PATH, "rb")) == NULL) {
        printf("error!");
        return;
    }
    // for rollback
    preFileReadPosition = fileReadPosition;
    fseek(fp, fileReadPosition, SEEK_SET);
    // 初始化关卡数
    if(fileReadPosition == 0) {
        fscanf(fp, "%d", &levels);
        readRecords();
    }
    fscanf(fp, "%d", &supposedMoves);
    fscanf(fp, "%d", &rows);
    fscanf(fp, "%d", &cols);
    int t;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &map[i][j]);
            if (map[i][j] == NUM_PLAYER) {
                playerX = j;
                playerY = i;
                // positions of holders are stored in an array, not the map
            }else if( (t = map[i][j]) == NUM_HOLDER || t == NUM_BOX_HOLDER || t == NUM_PLAYER_HOLDER){
                holders[0][holderSize] = j; // x
                holders[1][holderSize] = i; // y
                ++holderSize;
                if(t == NUM_HOLDER) {
                    map[i][j] = 0;
                }else if(t == NUM_BOX_HOLDER) {
                    map[i][j] = NUM_BOX;
                }else if(t == NUM_PLAYER_HOLDER) {
                    map[i][j] = NUM_PLAYER;
                    playerX = j;
                    playerY = i;
                }
            }
        }
    }
    fileReadPosition = ftell(fp);
    fclose(fp);
    printMap();
    printHolders();
    printInfo();
}

bool checkWin() {
    for(int i = 0; i < holderSize; i++) {
        if(map[holders[1][i]][holders[0][i]] != NUM_BOX) {
            return false;
        }
    }
    return true;
}

void endGame() {
    playerWin = 1;
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


void showMenu() {
    int t;
    if(t = (score > records[currLevel - 1])) {
        records[currLevel - 1] = score;
        dumpRecords();
    }
    if(currLevel >= levels) {
        endGame();
        return;
    }
    system("cls");
    printf("You've passed level%d\n", currLevel);
    if(t) printf("Congratulations! You've just broken the record!!!\n");
    printf("Your score is %d, the record is %d\n", score, records[currLevel - 1]);
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
    if (map[playerY + DIR_ARR[1][dir]][playerX + DIR_ARR[0][dir]] == NUM_PATH) {
        ++currMoves;
        map[playerY][playerX] = NUM_PATH;
        gotoxy(2 * playerX, playerY);
        printf("%s", SYMBLE_PATH);
        playerY += DIR_ARR[1][dir];
        playerX += DIR_ARR[0][dir];
        map[playerY][playerX] = NUM_PLAYER;
        gotoxy(2 * playerX, playerY);
        printf("%s", SYMBLE_PLAYER);
        printInfo();
        // 有可能box被推到holder上又被推走(或者player从holder上经过)，需要重新打印holder
        printHolders();
    } else if (map[playerY + DIR_ARR[1][dir]][playerX + DIR_ARR[0][dir]] == NUM_BOX && map[playerY + 2 * DIR_ARR[1][dir]][playerX + 2 * DIR_ARR[0][dir]] == NUM_PATH) {
            ++currMoves;
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
            printInfo();
            if(checkWin()) {
                // score =  caclScore(supposedMoves, currMoves);
                ++currLevel;
                dumpScore();
                showMenu();
            }
            // 有可能box被推到holder上又被推走(或者player从holder上经过)，需要重新打印holder
            printHolders();
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
            case 114:
                // restart current level
                fileReadPosition = preFileReadPosition;
                initMap();
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
