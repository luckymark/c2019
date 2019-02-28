#include<iostream>
#include<cmath>            
using namespace std;
int main()
{
	for (int x = 1; x <= 9; x++)
		for (int y = 0; y <= 9; y++)
			for (int z = 0; z <= 9; z++)
				if (x*x*x + y *y*y + z *z*z == 100 * x + y * 10 + z)
					cout << 100 * x + y * 10 + z << " ";
	system("pause");
}