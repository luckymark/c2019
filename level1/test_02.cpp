#include<iostream>
using namespace std;
void hanoi(int n, char a, char b, char c);
int main()
{
	int n;
	cin >> n;
	hanoi(n, 'a', 'b', 'c');

}


void hanoi(int n, char a, char b, char c)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		hanoi(n - 1, a, c, b);
			cout << a << "->" << c<<endl;
			hanoi(n - 1, b, a, c);
	}
}