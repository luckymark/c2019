#include<iostream>
#include<cmath>
using namespace std;
void build_primelist(int* A);
bool ISprime(int x);
const int MAX = 1000000;
int A[MAX];

int main()    //本代码使用筛法,最大上限为一百万(一个亿太大了。。。算了20几秒数组都还没算完)
{
	build_primelist(A);
	 int n;
	cin >> n;
	if (n == 1)
		cout << "1既不是质数也不是和数";
	else if (A[n] == 1)
		cout << "是质数";
	else cout << "是和数";  
	
	system("pause");
}

bool ISprime(int x)
{
	if (x % 2 == 0)
		return 0;
	for (int i = 2; i <=int(sqrt(x)); i++)  
	{
		if (x%i == 0)
			return false;
	}
	return true;   
	
}

void build_primelist(int* A)
{
	fill_n(A, MAX, 1);

	for (int i = 3; i <= MAX; i++)
	{
		if (i % 2 == 0)
			A[i] = 0;
		if (!ISprime(i))
		{
			int b = i;
			for (int n = 1; b <= MAX; b *= n, n++)
				A[b] = 0;

		}
	}
	
}