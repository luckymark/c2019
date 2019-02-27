#include <iostream>
#include <time.h>

using namespace std;
const int MAXN = 100;

int isprime[MAXN + 5], primes[MAXN + 5], len;

void GetPrime()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= MAXN; i++)
	{
		if (isprime[i])primes[len++] = i;
		for (int j = 0; j < len; j++)
		{
			if (i*primes[j] > MAXN) break;
			isprime[i*primes[j]] = false;
			if (i%primes[j] == 0) break;
		}
	}
}

int main()
{
	GetPrime();
	bool flag;
	for (int i = 4; i <= 100; i += 2)
	{
		flag = false;
		for (int j = 0; j < len; ++j)
		{
			if (isprime[i - primes[j]])
				flag = true;
		}
		if (flag == false)
		{
			printf("false\n");
			return 0;
		}
	}
	printf("true\n");
	//system("pause");
	return 0;
}
