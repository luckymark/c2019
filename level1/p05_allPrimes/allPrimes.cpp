#include<cstring>
#include<cstdio>
#include<ctime>

const int L = 1002;

bool isPrime[L];

void getPrime()       //œﬂ–‘…∏
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
	clock_t startTime = clock();
	getPrime();
	for (int s = 2; s <= 1000; s++)
		if (isPrime[s])
			printf("%d ", s);
	clock_t endTime = clock();
	printf("\n\nTime: %.12lf", (double)(endTime - startTime) / CLOCKS_PER_SEC);
}
