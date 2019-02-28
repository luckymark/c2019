#include <stdio.h>
#include <stdlib.h>

int Just(int x, int y, int z);

int main()
{
	int i, j, k;
	for (i = 1; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			for (k = 0; k <= 9; k++)
			{
				if (Just(i, j, k) == i * 100 + j * 10 + k)
				{
					printf("%d ", i * 100 + j * 10 + k);
				}
				else if (i == 9 && j == 9 && k == 9)
				{
					system("pause");
					return 0;
				}
			}
		}
	}
}

int Just(int x, int y, int z)
{
	return x * x*x + y * y*y + z * z*z;
}