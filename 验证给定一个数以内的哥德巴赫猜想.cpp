#include<iostream>
#include<cmath>
using namespace std;
int build_primelist(void);
bool ISprime(int x);
bool inquire(int *A,int a,int b); //查找数组内是否有元素a是数组大小,b是你要查找的元素
const int MAX = 1000000;
int A[MAX];

int main()    
{ 
	int p=build_primelist();//p为MAX以内的质数个数
	int *B = new int[p + 1];
	int n = 1;
	for (int i = 2; i <= MAX; i++)   //生成一个全是质数的数组B
		if (A[i] == 1)
		{
			B[n] =i;
			n++;
		}


			for (int i = 4; i <= MAX; i+=2)   //下面开始验证
			
				
					for (int a = 1; B[a]<i; a++)
					{
						if (inquire(B, p + 1, i - B[a]))
						{
							cout << i << "符合哥德巴赫猜想,其为" <<B[a]<<"+"<<i-B[a]<< endl;
							break;
						}
					}
				
			delete[]B; system("pause");
				
}

bool ISprime(int x)
{
	if (x > 6)
	{
		if (x % 6 != 1 && x % 6 != 5)     //质数只能是6n+1或者是6n-1的形式
			return false;
	}
	if (x % 2 == 0)
		return false;
	for (int i = 2; i <= int(sqrt(x)); i++)
	{
		if (x%i == 0)
			return false;
	}
	return true;

}

int build_primelist(void)
{
	int b = 0;
	fill_n(A, MAX, 1);
	for (int i = 3; i <= MAX; i++)
	{
		if (ISprime(i))
			b++;
		if (i % 2 == 0)
			A[i] = 0;
		if (!ISprime(i))
		{
			int b = i;
			for (int n = 1; b <= MAX; b *= n, n++)
				A[b] = 0;
		}
	}
	return b;
	
}

bool inquire(int *A, int a, int b)
{
	for (int i = 1; i <= a; i++)
		if (A[i] == b)
			return true;

	return false;
}