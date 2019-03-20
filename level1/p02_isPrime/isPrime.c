#include <stdio.h>
#include <math.h>

typedef long long ll;

int isPrime(ll x)
{
    if(x==1)return 0;
	ll sq = sqrt(x);
	for (int i = 2; i <= sq; ++i)
	{
		if (x%i == 0)return 0;
	}
	return 1;
}

int main()
{
	ll num;
	scanf("%I64d",&num);
	if (isPrime(num))printf("a prime\n");
	else printf("not a prime\n");
	return 0;
}
