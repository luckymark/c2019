#pragma GCC optimize(3, "Ofast", "inline")

#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

#include "bigDecimal.h"

clock_t startTime = clock();

BigDecimal tmpA(0, 0), tmpB(0, 0), tmpT(0, 0);

void calcPI(BigDecimal a, BigDecimal b, BigDecimal t, int p, int time)
{
	for (int s = 1; s <= time; s++)
	{
		printf("Loop %d", s);
		//(((a+b).div2()*(a+b).div2()) / t).printDecimal();
		tmpA = (a + b).div2();
		tmpB = (a * b).sqrt();
		tmpT = t - ( ( ((a - b) * (a - b)) << p ).div2() ).div2();
		a = tmpA;
		b = tmpB;
		t = tmpT;
		p++;
		clock_t curTime = clock();
		printf("       %lfs\n", (double)(curTime - startTime) / CLOCKS_PER_SEC);
		if (s == time)
		{
			printf("\n");
			(((a + b).div2() * (a + b).div2()) / t).printDecimal();
			return;
		}
	}
}

int main()
{
	//freopen("10k_++.txt", "w", stdout);
	BigDecimal a(1, 0);
	BigDecimal b(2, 0);
	BigDecimal t(1, 0);
	BigDecimal c(0, 0);
	//(a/b).printDecimal();

	b = b.sqrt().div2();
	t = t.div2().div2();

	calcPI(a, b, t, 0, 14);
	clock_t endTime = clock();
	printf("\nTime: %lfs\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
}
