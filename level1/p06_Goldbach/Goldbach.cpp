#include<cstring>
#include<cstdio>
#include<ctime>

const int L = 10002;

bool isPrime[L];

int primes[L], prCnt = 0;

int maxC = 1000;

void getPrime()                                        //线性筛
{
	for (int s = 0; s < L; s++) isPrime[s] = 1;
	isPrime[0] = isPrime[1] = 0;
	for (int s = 2; s < L; s++)
		if (isPrime[s])
			for (int t = 2; t*s < L; t++)
				isPrime[s*t] = 0;
	for (int s = 0; s < L; s++)
		if (isPrime[s])
			primes[prCnt++] = s;                       //把筛好的质数排在一个数组中，方便用
}

bool check(int x)
{
	int half = x / 2;
	for (int s = 0; primes[s] <= half; s++)
		if (isPrime[x - primes[s]])
			return 1;
	return 0;
}

int main()
{
	getPrime();
	bool right = 1;
	for (int s = 4; s <= maxC; s += 2)
	{
		printf("%d %d\n", s, check(s));                //对于每个数如果验证正确为1，否则为0
		right &= check(s);
	}
	if (right) printf("在%d之内正确", maxC);
}
