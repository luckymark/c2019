#include"empty.h"
#include"near.h"
void empty(board_empty* empty1)//���е�λ��
{
	int i, j, k = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < length; j++)
		{
			if ((board[i][j] == 0) && near1(i, j))//�����ӵĿ���,��Ϊ�����ӵĶ���
			{
				empty1->board9[k].x = i;
				empty1->board9[k].y = j;
				empty1->len = k + 1;
				k++;
			}
		}
	}
}