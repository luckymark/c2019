#include <stdio.h>
#include <stdlib.h>
#include "move.h"

extern int board[SIZE][SIZE];
int ai_turn;

DPT *move(){
    // 在有子的位置附近选一些空位置，存成一个链表
    DPT *head;
    head = select_point();

    // 判断AI是先手还是后手
    ai_turn = judge_turn();

    // 找到栈内估值最大的点
    int height = DEPTH;
    DPT *goad;
    do{
        goad = dp(head, ai_turn, height);
        --height;
    }while(board[goad->x][goad->y]);

    return goad;
}

DPT *dp(DPT *head, int turn, int height){
    DPT *max_head = (DPT*)malloc(sizeof(DPT));
    max_head->x = SIZE/2;
    max_head->y = SIZE/2;
    max_head->value = -INF;

    while(head != NULL){
        // 一个落点的值，等于棋子落在这个位置上时对棋盘的改变
        head->value = head->value - evalue(head, turn);
        board[head->x][head->y] = turn;     // 落子
        head->value = head->value + evalue(head, turn);

        // 如果在第一层时就使棋盘上出现五子连珠，直接返回即可
        // 否则，返回上一层跳过这种选择
        if(head->fives){
            head->is_win = TRUE;
            board[head->x][head->y] = EMPTY;    // 收子
            return head;
        }

        if(height > 1){
            DPT *new_head = select_point();
            int next_turn = (turn == BLACK) ? WHITE :BLACK;
            DPT *next_point = dp(new_head, next_turn, height-1);    // 敌方走子
            if(next_point->is_win){
                board[head->x][head->y] = EMPTY;    // 收子
                head = head->next;
                continue;
            }
            head->value = head->value - next_point->value;
        }

        board[head->x][head->y] = EMPTY;    // 收子

        if(head->value > max_head->value)
            max_head = head;

        head = head->next;
    }

    return max_head;
}
