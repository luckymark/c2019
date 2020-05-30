//  sqrt(n)·½·¨

#include<cstring>
#include<cstdio>
#include<cmath>

bool check(int x)
{
	if (x == 1) return 0;
	int maxl = sqrt(x);
	for (int s = 2; s <= maxl; s++)
		if (x%s == 0)
			return 0;
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	if (check(n)) printf("a prime\n");
	else printf("not a prime\n");
}
