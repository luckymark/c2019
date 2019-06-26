#include"assume.h"
#include"allcalculate.h"
#include"basic.h"
#include"empty.h"
#include"generate_evaluate.h"
void assume()
{
    int i,j=0;
	int x, y;
	//int test = 0;
    int scoremax=0;
    int scorenumberi=0;
    int scorenumberj=0;
	int maxscore=MIN;
	int alfa  = MIN;
	int beta  = MAX;
	board_empty tempposition;
	board_empty sureposition;
	//empty(&tempposition);
	generate_evaluate(&tempposition);//生成排序后的点顺序
	for (i = 0; i <tempposition.len; i++)
	{

      	x = tempposition.board9[i].x;
		y = tempposition.board9[i].y;
		board[x][y] = 2;//尝试下一步
		userposition_x = x;
		userposition_y = y;
		scoremax = minalfa(depth-1 , MIN, MAX);
		if (maxscore ==scoremax)
		{
			sureposition.board9[j].x= tempposition.board9[i].x;
			sureposition.board9[j].y = tempposition.board9[i].y;
			sureposition.len = j + 1;
			j++;
		}//储存适合的点
		if (maxscore < scoremax)
		{
			
			maxscore = scoremax;
			sureposition.len = 1;
			j = 0;
			sureposition.board9[j].x = tempposition.board9[i].x;
			sureposition.board9[j].y = tempposition.board9[i].y;
			j++;
		}//更新适合的点
		board[x][y] = 0;//恢复下的那一步
	}
	srand(time(NULL));
	j = rand()% sureposition.len;//在符合条件的点中随机选择一个下;
	position2_x = sureposition.board9[j].x;
	position2_y = sureposition.board9[j].y;
	board[position2_x][position2_y] = 5;
	temp_x=userposition_x = position2_x;
	temp_y=userposition_y = position2_y;
}

