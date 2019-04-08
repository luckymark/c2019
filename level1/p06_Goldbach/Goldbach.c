#pragma warning(disable:4996)
#include<stdio.h>
int x[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };
int a[100];
int main(void)
{
	int n;
	int s = 1;
	for (n = 4; n < 101; n = n + 2)
	{
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (x[i] + x[j] == n)
				{
					a[n]++;
					break;
				}
			}
			if (a[n])
				break;
		}
	}
	for (n = 4; n < 101; n = n + 2)
	{
		s *= a[n];
	}
	if (s == 1)
		printf("Validated the correctness of the Goldbach conjecture in the 100 range.");
	return 0;
}