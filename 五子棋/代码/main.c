#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
#include "main.h"

int board[SIZE][SIZE];

int main() {
    // 读入一个棋盘
    scan_board();

    // 走一步
    DPT *head;
    head = move();
    printf("%d %d\n", head->x, head->y);

    free(head);

    return 0;
}
