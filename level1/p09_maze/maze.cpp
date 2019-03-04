#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

/**
 * todo: 
 * 1.双缓冲解决闪烁问题
 * 2.随机生成迷宫
 */

using namespace std;

const int NUM_PATH = 0;
const int NUM_WALL = 1;
const int NUM_PLAYER = 2;
const int NUM_EXIT = 4;

const char SYMBLE_PATH = ' ';
const char SYMBLE_WALL = '#';
const char SYMBLE_PLAYER = '@';
const char SYMBLE_EXIT = '*';

const int MAP_MAX_SIZE = 50;

const int DIR_UP = 0;
const int DIR_DOWN = 1;
const int DIR_LEFT = 2;
const int DIR_RIGHT = 3;

const int DIR_ARR[2][4] = {
    {0, 0, -1, 1},  // x
    {-1, 1, 0, 0}   // y
};

struct Point {
    int x;
    int y;
};

class Map {
   public:
    int rows, cols;
    int startX, startY;
    int endX, endY;
    int map[MAP_MAX_SIZE][MAP_MAX_SIZE];
    Map(const char* mapFile);
    void printMap();
};

class Player {
   public:
    bool win;
    Map map;
    Point pos;
    Player(const char* mapFile);
    void move(int dir);
    void checkWin();
};

class Game {
   public:
    Player player;
    Game(const char* mapFile);
    void start();
    void showBanner();
    void end();
};

Game::Game(const char* mapFile) : player(mapFile) {}

void Game::start() {
    char key;
    while (!player.win) {
        key = getch();
        switch (key) {
            case 119:
                player.move(DIR_UP);
                break;
            case 115:
                player.move(DIR_DOWN);
                break;
            case 97:
                player.move(DIR_LEFT);
                break;
            case 100:
                player.move(DIR_RIGHT);
                break;
            default:
                break;
        }
    }
    end();
}

void Game::showBanner() {
    system("cls");
    ifstream infile("banner.txt", ios::in);
    if (!infile.is_open()) {
        cout << "cannot open file banner.txt!" << endl;
        return;
    }
    string s;
    int i = 0;
    while (!infile.eof()) {
        getline(infile, s);
        cout << s << endl;
    }
    infile.close();
}

void Game::end() {
    showBanner();
    system("pause");
}

Player::Player(const char* mapFile) : map(mapFile) {
    // init Player's position
    pos.x = map.startX;
    pos.y = map.startY;
}

void Player::move(int dir) {
    if (map.map[pos.y + DIR_ARR[1][dir]][pos.x + DIR_ARR[0][dir]] != NUM_WALL) {
        map.map[pos.y][pos.x] = NUM_PATH;
        pos.y += DIR_ARR[1][dir];
        pos.x += DIR_ARR[0][dir];
        map.map[pos.y][pos.x] = NUM_PLAYER;
        map.printMap();
        checkWin();
    }
}

void Player::checkWin() {
    if (pos.x == map.endX && pos.y == map.endY) {
        win = true;
    }
}

Map::Map(const char* mapFile) {
    ifstream infile(mapFile, ios::in);
    if (!infile.is_open()) {
        cout << "cannot open file banner.txt!" << endl;
        return;
    }
    infile >> rows >> cols;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            infile >> map[i][j];
            if (map[i][j] == NUM_PLAYER) {
                startX = j;
                startY = i;
            } else if (map[i][j] == NUM_EXIT) {
                endX = j;
                endY = i;
            }
        }
    }
    infile.close();
    // border
    for (int i = 0; i < rows + 2; i++) {
        map[i][0] = 1;
        map[i][cols + 1] = 1;
    }
    for (int i = 0; i < cols + 2; i++) {
        map[0][i] = 1;
        map[rows + 1][i] = 1;
    }
    printMap();
}

void Map::printMap() {
    system("cls");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            switch (map[i][j]) {
                case NUM_PATH:
                    cout << SYMBLE_PATH << " ";
                    break;
                case NUM_WALL:
                    cout << SYMBLE_WALL << " ";
                    break;
                case NUM_PLAYER:
                    cout << SYMBLE_PLAYER << " ";
                    break;
                case NUM_EXIT:
                    cout << SYMBLE_EXIT << " ";
                    break;
                default:
                    break;
            }
        }
        cout << endl;
    }
}

void consoleInit(){
    system("color 2");
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main() {
    consoleInit();
    Game game("map.txt");
    game.start();
    return 0;
}
