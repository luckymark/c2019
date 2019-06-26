#include <stdio.h>
void attack_start(int n,char *a[30])
{
	int i,j;
	if (n == 0)
	{
		for (i = 1; i < 30; i = i + 2)
		{
			for (j = 0; j < 29; j = j + 2)
			{
				if (a[i][j] == 'X')
				{
					a[i + 2][j + 2] = 'O'; break;
				}
			}
		}
	}
} 