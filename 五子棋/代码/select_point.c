#include <stdio.h>
#include <stdlib.h>
#include "select_point.h"

extern int board[SIZE][SIZE];

// 把有子的位置附近的空位置存进一个链表，返回表头
DPT *select_point(){
    DPT *head;
    head = NULL;

    for(int i = 0; i < SIZE; ++i)
        for(int j = 0; j < SIZE; ++j)
            if(!board[i][j] && have_neighbour(i, j)) {
                DPT *newdpt = (DPT *) malloc(sizeof(DPT));
                newdpt->x = i;
                newdpt->y = j;
                newdpt->value = 0;
                newdpt->fives = 0;
                newdpt->is_win = FALSE;
                newdpt->next = head;
                head = newdpt;
            }

    return head;
}

// 判断一个空位附近是否有子
BOOL have_neighbour(int x, int y){
    int ub, lb, leftb, rightb;
    ub = (x-2 >= 0) ? x-2 : 0;
    lb = (x+2 < SIZE) ? x+2 : SIZE-1;
    leftb = (y-2 >= 0) ? y-2 : 0;
    rightb = (y+2 < SIZE) ? y+2 : SIZE-1;

    for(int i = ub; i <= lb; ++i)
        for(int j = leftb; j <= rightb; ++j)
            if(board[i][j])
                return TRUE;

    return FALSE;
}
