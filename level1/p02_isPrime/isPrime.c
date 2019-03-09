#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	int n;
	int s = 0;
	scanf("%d", &n);
	for (int i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
			s++;
	}
	if (s == 0)
		printf("%d是素数。", n);
	else
		printf("%d不是素数。", n);
	
	return 0;
}
