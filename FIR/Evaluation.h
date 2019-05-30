#ifndef EVALUATION_H
#define EVALUATION_H

//These functions are for whole board search
int Left_Right2(char board[N][N][L],int state);		//state:PChar
int Up_Down2(char board[N][N][L],int state);
int Left_Up2(char board[N][N][L],int state);
int Left_Down2(char board[N][N][L],int state);
int Evaluation(char board[N][N][L],int side);		//给某一方评分，分数为正	side:BLACK or WHITE

#endif
