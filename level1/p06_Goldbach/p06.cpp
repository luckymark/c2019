#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int getPrime(int, bool*, int*, int*);
int Goldbach(int, bool*, int*, int*);

int main()
{
	const int maxN = 100;
	cin.sync_with_stdio(0);
	cin.tie(0);
	bool notPrime[maxN + 1] = { 0 };
	int primeList[maxN];
	int primeN = 0;
	getPrime(maxN, notPrime, primeList, &primeN);

	if (Goldbach(maxN, notPrime, primeList, &primeN))
	{
		cout << "All even numbers between 4 and " << maxN << " meet the Goldbach conjecture.";
	}
	else
	{
		cout << "Some numbers don't meet the Goldbach conjecture.";
	}
	
	return 0;
}

int getPrime(int maxN, bool * notPrime, int * primeList, int * primeN)
{
	notPrime[0] = notPrime[1] = true;
	for (int i = 2; i <= maxN; i++)
	{
		if (!notPrime[i])
		{
			primeList[*primeN] = i;
			(*primeN)++;
			for (int j = i * i; j <= maxN; j += i)
				notPrime[j] = true;
		}
	}
	return 0;
}

int Goldbach(int maxN, bool * notPrime, int * primeList, int * primeN)
{
	bool GoldbachAccepted = true;
	for (int sum = 4; sum <= maxN; sum += 2)
	{
		int half = sum / 2;
		for (int j = 0; j < *primeN; j++)
		{
			if (primeList[j] > half) //not found;
			{

				GoldbachAccepted = false;
				cout << sum << "not found" << endl;
				break;
			}
			if (!notPrime[sum - primeList[j]])
			{
				cout << primeList[j] << "+" << sum - primeList[j] << "=" << sum << endl;
				break;
			}
		}
	}
	return GoldbachAccepted;
}
