#include<stdio.h>
#include <stdlib.h>
struct Board{
	int status;
};
extern struct Board board[15][15];
void printf_board();
void judge(int b);
int evaluation(int chesscolour); 
int sense();
int ai_move();



