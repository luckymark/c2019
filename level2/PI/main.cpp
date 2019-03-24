#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

#include "bigDecimal.cpp"

clock_t startTime = clock();

void calcPI(BigDecimal a, BigDecimal b, BigDecimal t, int p, int time)
{
	for (int s = 1; s <= time; s++)
	{
		printf("Loop %d", s);
		BigDecimal tmpA(0, 0), tmpB(0, 0), tmpT(0, 0);
		tmpA = (a+b).div2();
		tmpB = a.sqrt()*b.sqrt();
		tmpT = t-( (((a-b)*(a-b)) << p).div2()).div2();
		a = tmpA;
		b = tmpB;
		t = tmpT;
		p++;
		clock_t curTime = clock();
		printf("       %lfs\n", (double)(curTime - startTime) / CLOCKS_PER_SEC);
		if (s == time)
		{
			printf("\n");
			(((a+b).div2()*(a+b).div2()) / t).printDecimal();
		}
	}
}

int main()
{
	BigDecimal a(1, 0);
	BigDecimal b(2, 0);
	BigDecimal t(1, 0);

	b = b.sqrt().div2();
	t = t.div2().div2();

	calcPI(a, b, t, 0, ITERATION_TIME - 1);
	clock_t endTime = clock();
	printf("\nTime: %lfs\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
}
