#include<iostream>
#include<string>
#include<time.h>
using namespace std;
string A;
void lock(int *a,int b);
void unlock(int *a, int b);
int main()
{
	srand(time(NULL));
	string *p = &A;
	cin >> A;
	int length = A.size();
	int *a = new int [length+1];

	for (int i = 0; i <= length; ++i)
	{
		a[i] = i;
	}
		for (int i = 1; i <=length-1; i++) 
			swap(a[i], a[rand()%i]); //随机生成密钥
		
		lock( a, length);
		cout << A<<endl;
		unlock(a, length);
		cout << A;
		system("pause");
}


void lock(int *a, int length)
{
			for (int i = 0; i <= length-1; i++)
		{
			A[i] = A[i] ^ A[a[i]];
			A[a[i]] = A[i] ^ A[a[i]];
			A[i] = A[i] ^ A[a[i]];
		}    //利用密钥先进行交换操作
		for (int i = 0; i <= length - 1; i++)
			A[i] +=pow(2, a[i]);
};  


void unlock(int *a, int length)
{
	for (int i = 0; i <= length - 1; i++)
		A[i] -= pow(2, a[i]);
	for (int i = length - 1; i >= 0; i--)
	{
		A[i] = A[i] ^ A[a[i]];
		A[a[i]] = A[i] ^ A[a[i]];
		A[i] = A[i] ^ A[a[i]];
	}
}