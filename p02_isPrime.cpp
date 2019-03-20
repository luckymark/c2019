#include<iostream>
using namespace std;
int main() {
	int n; bool f = true;
	cout << "请输入一个整数:";
	cin >> n;
	if (n == 2)cout << "这是一个素数";
		for (int i = 2; i*i <= n; i++) 
			if (n%i == 0)f = false;
	if (!f)cout << "这不是一个素数";
	else cout << "这是一个素数";
	return 0;
}