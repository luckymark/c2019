#include"empty.h"
#include"near.h"
void empty(board_empty* empty1)//空闲的位置
{
	int i, j, k = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < length; j++)
		{
			if ((board[i][j] == 0) && near1(i, j))//有棋子的空子,做为可下子的队列
			{
				empty1->board9[k].x = i;
				empty1->board9[k].y = j;
				empty1->len = k + 1;
				k++;
			}
		}
	}
}