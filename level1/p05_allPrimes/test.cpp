#include<stdio.h>
//#include<stdlib.h>
#include<time.h>

int main() {
	int prime[200] = { 2 };		// 用于存放找到的素数
	long start, finish;			// 开始和结束的时刻
	int i;						// 循环专用变量

	start = clock();        // 计时开始

	// 所有比某素数小的素数都不是该素数的因子
	for (int n = 3; n < 1000; ++n) {
		for (i = 0; prime[i]; ++i)
			if (0 == n % prime[i])
				break;
		if (!prime[i])
			prime[i] = n;
	}

	finish = clock();       //计时结束

	for (i = 0; prime[i]; ++i) {
		printf("%d\t", prime[i]);
		if (0 == (i + 1) % 10)
			printf("\n");
	}
	printf("\n\nTotal time is %f second.\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return 0;
}
