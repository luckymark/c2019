#ifndef AI_H
#define AI_H

int notused(int m,int n,char board[N][N][L]);
void Level_0_Rand(char board[N][N][L]);
void Level_01_Greedy(char board[N][N][L]);
void Level_1_Max_Min(char board[N][N][L]);
void Level_2_ABcut(char board[N][N][L]);
int EmulateValue(char board[N][N][L],int side,int m,int n);		//根据最后落子估值				side:BLACK or WHITE
int insight(int m,int n,char board[N][N][L]);				//判断是否在已下子的周围
int EmulateValueForMaxMin(char board[N][N][L],int m,int n,int depth);				//depth表示递归搜索层数，必须为偶数
int EmulateValueForABcut(char board[N][N][L],int m,int n,int depth,int lastval);

#endif
