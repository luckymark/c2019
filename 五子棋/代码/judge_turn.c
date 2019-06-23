#include "test2.h"

extern int board[SIZE][SIZE];

int judge_turn(){
    int sum = 0;
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            sum = sum + board[i][j];
        }
    }

    if(sum % 3)
        return WHITE;
    else
        return BLACK;
}
