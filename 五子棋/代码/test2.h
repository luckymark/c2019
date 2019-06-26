#ifndef TEST2_TEST2_H
#define TEST2_TEST2_H

#endif //TEST2_TEST2_H

#define SIZE 15     // 棋盘大小
#define DEPTH 2     // 深搜的层数

#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define END 3

#define BOOL int
#define TRUE 1
#define FALSE 0

#define INF 2147483647

typedef struct droppoint{
    int x;
    int y;
    int value;
    int fives;
    BOOL is_win;
    struct  droppoint *next;
}DPT;
