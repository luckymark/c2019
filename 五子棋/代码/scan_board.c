#include <stdio.h>
#include "test2.h"

extern int board[SIZE][SIZE];

void scan_board(){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            scanf("%d", &board[i][j]);
        }
    }
}
