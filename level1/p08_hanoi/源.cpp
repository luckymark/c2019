#include<stdio.h>
 long int s = 0;
void move(int a, int start, int end) {
	if (a == 1) {
		printf_s("%d->%d\n", start, end);
		s++;
	}
	else {
		move(a - 1, start, 6 - start - end);
		printf_s("%d->%d\n", start, end); 
		s++;
		move(a - 1, 6 - start - end, end);
	}
}
int main() {
	int a;
	printf_s("请输入要移动的个数");
	scanf_s("%d", &a);
	move(a, 1, 2);
	printf_s("总共移动%l次", s);
	return 0;
}