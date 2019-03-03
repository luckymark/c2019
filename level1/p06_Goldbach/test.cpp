#include<stdio.h>

int prime[50] = { 2 };		// 用于存放找到的素数

inline bool isRight(int &n) {
	for (int i = 0; prime[i]; ++i)
		for (int j = 0; prime[j]; ++j)
			if (prime[i] + prime[j] == n)
				return true;
	return false;
}

int main() {
	int i;			// 循环专用变量

	// 得到 100 之内的所有素数
	for (int n = 3; n < 1000; ++n) {
		for (i = 0; prime[i]; ++i)
			if (0 == n % prime[i])
				break;
		if (!prime[i])
			prime[i] = n;
	}
	// 遍历验证猜想
	for (i = 4; i < 100; i += 2)
		if (!isRight(i)) {
			printf("Goldbach is wrong!");
			break;
		}
	if (100 == i)
		printf("Goldbach is right!");
	return 0;
}
