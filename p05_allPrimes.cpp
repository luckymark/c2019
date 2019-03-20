#include<iostream>
#include<cstring>
using namespace std;
int main() {
	bool isPrime[101];
	memset(isPrime, true, sizeof(isPrime));
		for (int i = 2; i*i <= 100; i++) {
			if (isPrime[i])
			{
				for (int j = 2; i*j <= 100; j++)
					isPrime[i*j] = false;
			}
		}
	for (int i = 2; i <= 100; i++)
		if (isPrime[i])cout << i << endl;
	return 0;
}