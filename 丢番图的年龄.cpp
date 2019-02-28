#include<iostream>
#include <limits.h>
using namespace std;
int AGE = 12*7;
int son_birth;
int son_death;
int main()
{//这道题有个小技巧，因为年龄必然是整数，而题目又给了1/6,1/12,1/7，所以其年龄必为12,7的公倍数(6和12合并为12)

	int son_birth = AGE / 6 + AGE / 12 + AGE / 7 + 5;
	int son_death = AGE - 4;
		for (int i = 1;AGE< INT_MAX; AGE *= i, i++)   //其实没必要设置那个无限大，但是以防无解而无限循环，设置了一个最大值
		{
			if (son_death - son_birth == AGE / 2)
			{
				cout << AGE;
				break;
			}
		}
		system("pause");
}