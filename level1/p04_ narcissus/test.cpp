#include<stdio.h>
#include<math.h>

inline bool isNarcissus(int &n) {
	int bai, shi, ge;
	bai = n / 100;
	shi = n % 100 / 10;
	ge = n % 10;
	if (n == pow(bai, 3) + pow(ge, 3) + pow(shi, 3))
		return true;
	else
		return false;
}

int main() {
	for (int i = 100; i < 1000; ++i)
		if (isNarcissus(i))
			printf("%d\n", i);
	return 0;
}
