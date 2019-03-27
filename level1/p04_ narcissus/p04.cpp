#include <iostream>
#include <cmath>

using namespace std;

int Narcissus(int, int);

int main()
{
	const int length = 3;

	int low = pow(10, length - 1), up = pow(10, length) - 1;
	bool existNarcissus = false;
	for (int n =  low; n <= up; n++)
		if (Narcissus(n,length))
		{
			if (existNarcissus == false)
			{
				existNarcissus = true;
				cout << "The Narcissus numbers between " << low << " and " << up << " are as follows:\n";
			}
			cout << n << " ";
		}
	if (!existNarcissus)
		cout << "There isn't any Narcissus number between " << low << " and " << up << ".";
}

int Narcissus(int n, int length)
{
	int sum = 0, temp = n;
	for (int i = 0; i < length; i++)
	{
		sum += pow(temp % 10, length);
		temp /= 10;
	}
	return (n == sum);
}
