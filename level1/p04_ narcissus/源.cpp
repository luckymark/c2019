#include<stdio.h>
#include<math.h>
int main(){
	int n, a, b, c;
	int m;
	for (n = 100; n < 1000; n++){
		a = n / 100;
		m = n % 100;
		b = m / 10;
		c = m % 10;
		if (pow(a, 3) + pow(b, 3) + pow(c, 3) == n)printf_s("%d ", n);
	}
	return 0;
}