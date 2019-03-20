#include<iostream>
using namespace std;
void Move(int n,char a,char b,char c) {
	if (n == 1)cout << "把" << n << "从" << a << "放到" << c<<endl;
	else {
		Move(n - 1, a, c, b);
		cout << "把" << n << "从" << a << "放到" << c<<endl;
		Move(n - 1, b, a, c);
	}
}
int main() {
	int n;
	cout << "请输入总的圆盘数：";
	cin >> n;
	Move(n, 'a', 'b', 'c');
	return 0;
}