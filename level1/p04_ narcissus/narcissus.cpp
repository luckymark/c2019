#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y, z;
	for (int i = 100; i < 1000; ++i)
	{
		x = i / 100;
		y = (i - i / 100 * 100) / 10;
		z = i % 10;
		if (pow(x, 3) + pow(y, 3) + pow(z, 3) == i)
			printf("%d\n", i);
	}
	return 0;
}
