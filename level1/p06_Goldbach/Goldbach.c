#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAXN 100

int isprime[MAXN + 5], primes[MAXN + 5], len;

void GetPrime()
{
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	{
		if (isprime[i])primes[len++] = i;
		for (int j = 0; j < len; j++)
		{
			if (i*primes[j] > MAXN) break;
			isprime[i*primes[j]] = 0;
			if (i%primes[j] == 0) break;
		}
	}
}

int main()
{
	GetPrime();
	int flag;
	for (int i = 4; i <= 100; i += 2)
	{
		flag = 0;
		for (int j = 0; j < len; ++j)
		{
			if (isprime[i - primes[j]])
				flag = 1;
		}
		if (!flag)
		{
			printf("false\n");
			return 0;
		}
	}
	printf("true\n");
	//system("pause");
	return 0;
}
