#include <iostream>
#include <time.h>

using namespace std;
const int MAXN = 1000;

int notprime[MAXN + 5], primes[MAXN + 5], len;

void GetPrime()
{
	for (int i = 2; i <= MAXN; i++)
	{
		if (!notprime[i])
		{
			primes[len++] = i;
			printf("%d\n", i);
		}
		for (int j = 0; j < len; j++)
		{
			if (i*primes[j] > MAXN) break;
			notprime[i*primes[j]] = true;
			if (i%primes[j] == 0) break;
		}
	}
}

int main()
{
	clock_t StartTime, FinishTime;
	StartTime = clock();
	GetPrime();
	FinishTime = clock();
	printf("%.3lf seconds", (double)(FinishTime - StartTime) / CLOCKS_PER_SEC);
	//system("pause");
	return 0;
}
