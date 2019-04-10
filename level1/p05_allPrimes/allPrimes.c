#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)
int main()
{
	int  n;
	double b, e;
	b = clock();
	for (n = 2; n <= 1000; ++n)
	{
		int s = 0;
		for (int i = 2; i*i <= n; ++i)
		{
			if (n%i == 0)
				s++;
		}
		if (s == 0)
		{
			printf("%d ", n);
		}
	}
	e = clock();
	printf("\nTIME:%lfs", (e - b) / CLOCKS_PER_SEC);
	return 0;
}
