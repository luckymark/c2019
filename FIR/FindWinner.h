#ifndef FINDWINNER_H
#define FINDWINNER_H

int Left_Right(char board[N][N][L],int state);		//state:BLACK or WHITE
int Up_Down(char board[N][N][L],int state);
int Left_Up(char board[N][N][L],int state);
int Left_Down(char board[N][N][L],int state);
int JudgeBlack(char board[N][N][L]);
int JudgeWhite(char board[N][N][L]);

#endif
