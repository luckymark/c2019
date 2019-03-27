#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Pri[101];

void FindPrime(void);

int main()
{
	int n, i, j;
	bool done;
	FindPrime();
	for (n = 4; n <= 100; n + 2)
	{
		done = false;
		for (i = 2; i <= n / 2; i++)
		{
			if (Pri[i])
			{
				for (j = n - 2; j >= n / 2; j--)
				{
					if (Pri[j])
					{
						if (i + j == n)
						{
							printf("%d = %d + %d\n", n, i, j);
							done = true;
							break;
						}
					}
				}
			}
			if (done)
			{
				n = n + 2;
				break;
			}
		}
	}
	system("pause");
	return 0;
}

void FindPrime(void)
{
	int i;
	memset(Pri, 1, sizeof(bool) * 101);
	for (i = 2; i*i <= 100; i++)
	{
		if (Pri[i])
		{
			for (int j = 2; i*j <= 100; j++)
			{
				Pri[i*j] = false;
			}
		}
	}
}