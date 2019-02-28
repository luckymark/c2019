//  É¸·¨

#include<cstring>
#include<cstdio>
#include<cmath>

const int L = 1000000;

bool isPrime[L];

void getPrime()
{
	for (int s = 0; s < L; s++) isPrime[s] = 1;
	isPrime[0] = isPrime[1] = 0;
	for (int s = 2; s < L; s++)
		if (isPrime[s])
			for (int t = 2; t*s < L; t++)
				isPrime[s*t] = 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	getPrime();
	if (isPrime[n]) printf("a prime\n");
	else printf("not a prime\n");
}
