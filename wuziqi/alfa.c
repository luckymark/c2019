#include"alfa.h"
#include"generate_evaluate.h"
 
int minalfa(int deep, int alfa, int beta)
{
	//return allcalculate();
	int score = allcalculate();
	int i,x,y;
	int cut = 0;
	board_empty queue;
	int tmpscore;
	if (deep <= 0||exam())
	{
		return score;
	}
	//empty(&queue);
	generate_evaluate(&queue);
	for (i = 0; i < queue.len; i++)
	{
		cut++;
		x = queue.board9[i].x;
		y = queue.board9[i].y;
		board[x][y] = 4;
		userposition_x = x;
		userposition_y = y;
		tmpscore = maxalfa(deep - 1, alfa, beta );
		board[x][y] = 0;
		if (cut > 10)
		{
			break;
		}
		if (tmpscore <beta)
		{
			beta = tmpscore;
		}
		if (alfa >=beta)
		{
			break;
		}

	}
	return beta;
	
}
int maxalfa(int deep, int alfa, int beta)
{
	int res = allcalculate();
	int i, x, y;
	int cut = 0;
	int tmpscore;
	board_empty queue;
	if (deep <= 0 || exam())//上一步可能产生输赢
	{
		return res;
	}
	//生成可以下棋子的空子序列
	//empty(&queue);
	generate_evaluate(&queue);
	for (i = 0; i < queue.len; i++)
	{
		cut++;
		x = queue.board9[i].x;
		y = queue.board9[i].y;
		board[x][y] = 2;    //尝试下一个子
		userposition_x = x;
		userposition_y = y;
		tmpscore = minalfa(deep - 1,alfa, beta);
		board[x][y] = 0;          //恢复成空子
		if (cut > 10)
		{
			break;
		}
		if (tmpscore >alfa)
		{
			alfa= tmpscore;
		}
		if (alfa >= beta)
		{
			break;
		}
	}
	return alfa;

}
