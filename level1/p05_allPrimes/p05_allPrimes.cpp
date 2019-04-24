#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start, end;
	start = clock();
	bool Prime[1001];
	int i;
	for (i = 1; i <= 1000; i++)
	{
		Prime[i] = true;
	}
	for (i = 2; i*i <= 1000; i++)
	{
		if (Prime[i])
		{
			for (int j = 2; j*i <= 1000; j++)
			{
				Prime[j*i] = false;
			}
		}
	}
	for (i = 2; i <= 1000; i++)
	{
		if (Prime[i])
		{
			printf("%d\n", i);
		}
	}
	end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;
	printf("Used %f ms", duration);
	system("pause");
	return 0;
}
