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
	printf_s("������Ҫ�ƶ��ĸ���");
	scanf_s("%d", &a);
	move(a, 1, 2);
	printf_s("�ܹ��ƶ�%l��", s);
	return 0;
}