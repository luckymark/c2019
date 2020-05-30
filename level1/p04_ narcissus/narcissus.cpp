#include<cstdio>

int pow3(int x)
{
	return x * x * x;
}

bool check(int x)
{
	int a = x % 10;
	int b = (x/10) % 10;
	int c = (x/100) % 10;
	int num = pow3(a) + pow3(b) + pow3(c);
	if (x == num) return 1;
	return 0;
}

int main()
{
	for (int s = 100; s <= 999; s++)
		if (check(s))
			printf("%d ", s);
}
