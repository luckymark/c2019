#include<stdio.h>

void hanoi(int n, char from, char to, char by);
void move(char from, char to);

int main(void)
{
	int n, s = 1;
	printf("Please enter the number of discs.\n");
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		s *= 2;
	}
	printf("Need to move %d times,the steps are as follows:\n", s - 1);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void hanoi(int n, char from, char by, char to)
{
	if (n == 1)
		return;
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}

void move(char from, char to)
{
	printf("%c -> %c\n", from, to);
}