#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>

#include "bigDecimal.cpp"

int main()
{
	clock_t startTime = clock();
	BigDecimal a(1, 0);
	BigDecimal b(2, 0);
	b = b.sqrt().div2();
	BigDecimal t(1, 0);
	t = t.div2().div2();
	BigDecimal p(1, 0);
	calcPI(a, b, t, p, 1, 13);
	clock_t endTime = clock();
	printf("\nTime: %lfs\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
}
