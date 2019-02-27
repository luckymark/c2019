#include <iostream>
#include <cmath>

using namespace std;

int checkPrime(int);

int main()
{
	int num;
	cin >> num;
	int isPrime = checkPrime(num);
	if (isPrime == 1)
		cout << num << " is a prime number.";
	else if (isPrime == 0)
		cout << num << " is not a prime number.";
	else
		cout << num << " is an invalid input";
}

int checkPrime(int num)
{
	if (num < 1)
		return -1;
	int sqrt_n = sqrt(num);
	for (int i = 2; i < sqrt(num); i++)
		if (sqrt_n % i == 0)
			return 0;
	return 1;
}
