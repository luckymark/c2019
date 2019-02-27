#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

bool isPrime(ll x)
{
	ll sq = sqrt(x);
	for (int i = 2; i <= sq; ++i)
	{
		if (x%i == 0)return false;
	}
	return true;
}

int main()
{
	ll num;
	cin >> num;
	if (isPrime(num))cout << "a prime";
	else cout << "not a prime";
	return 0;
}
