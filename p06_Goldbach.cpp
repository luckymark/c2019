#include<iostream>
#include<cstring>
using namespace std;
int main() {
	bool Prime[101];
	memset(Prime, true, sizeof(Prime));
	for (int i = 2; i*i <= 100; i++) {
		if (Prime[i]) {for (int j = 2; i*j <= 100; j++)
				Prime[i*j] = false;
		}
	}
	int count = 0,a;
	for (int i = 4; i <= 100; i += 2) {
		for (int j = 2; j <= i; j++)
		{
			if (Prime[j]) {
				a = i - j;
				if (Prime[a]) { printf("第%d个符合猜想的偶数为%d,可以分解为%d和%d两个素数的和\n\n", ++count, i, a, j); break; }

			}
			else continue;
		}
		}
	return 0;
}