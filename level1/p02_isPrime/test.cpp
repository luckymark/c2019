#include <stdio.h>
#include <math.h>

bool isPrime(int &n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= (int)sqrt((double)n); ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main() {
	int n, i;
	while (scanf("%d", &n)) {
		if (isPrime(n))
			printf("%d是素数\n", n);
		else
			printf("%d不是素数\n", n);
	}
	return 0;
}