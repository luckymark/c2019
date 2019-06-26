#include <stdio.h>
int attack_live_3_1(int n, char *a[30])
{
	int i,j;
	if (n == 0)//判断是否防御成功 
	{
		for (i = 1; i < 30; i = i + 2)//利用“OOO”型活三进攻 
		{
			if (n == 1)break;
			for (j = 0; j < 29; j = j + 2)
			{
				if (((a[i][j] == ' ') || (a[i][j + 8] == ' ')) && (a[i][j + 2] == 'O') && (a[i][j + 4] == 'O') && (a[i][j + 6] == 'O'))
			{
				if (a[i][j] == ' ')
				{
					a[i][j] = 'O';
				}
				else a[i][j + 8] = 'O'; n = 1;
				break;
			}
			if (((a[i][j] == ' ') || (a[i + 8][j] == ' ')) && (a[i + 2][j] == 'O') && (a[i + 4][j] == 'O') && (a[i + 6][j] == 'O'))
			{
				if (a[i][j] == ' ')
				{
					a[i][j] = 'O';
				}
				else a[i + 8][j] = 'O'; n = 1;
				break;
			}
			if (((a[i][j] == ' ') || (a[i + 8][j + 8] == ' ')) && (a[i + 2][j + 2] == 'O') && (a[i + 4][j + 4] == 'O') && (a[i + 6][j + 6] == 'O'))
			{
				if (a[i][j] == ' ')
				{
					a[i][j] = 'O';
				}
				else a[i + 8][j + 8] = 'O'; n = 1;
				break;
			}
			if ((((a[i][j] == ' ') || (a[i + 8][j - 8] == ' ')) && (a[i + 2][j - 2] == 'O') && (a[i + 4][j - 4] == 'O') && (a[i + 6][j - 6] == 'O')) && (j > 10))
			{
				if (a[i][j] == ' ')
				{
					a[i][j] = 'O';
				}
				else a[i + 8][j - 8] = 'O'; n = 1;
				break;
			} 
		    }
    	} 
  	}
	return n;
}