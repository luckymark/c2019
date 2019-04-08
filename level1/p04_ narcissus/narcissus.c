#include<stdio.h>
int main()
{
	int a, b, c, i;
	for (i = 100; i < 1000; ++i)
	{
		a = i / 100;
		b = i / 10 - 10 * a;
		c = i - 100 * a - 10 * b;
		if (i == a * a*a + b * b*b + c * c*c)
		{
			printf("%d ", i);
		}
	}
}