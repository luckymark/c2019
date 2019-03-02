#include<cstdio>

void display(int k, int fromP, int toP)
{
	printf("MOV POLE%d, DISK%d from POLE%d\n", toP, k, fromP);
}

int move(int k, int a, int b, int c)    //递归的思想，要移动第k个必须先把第k-1个移开
{                                       //于是设移动n个的步数为F(n)，则F(n) = F(n-1) + 1 + F(n-1),  F(1) = 1
	int res = 0;
	if (k == 1)
	{
		display(k, a, c);
		return 1;
	}
	res += move(k-1, a, c, b);
	display(k, a, c);
	res += move(k-1, b, a, c);
	return res + 1;
}

int main()
{
	int n, steps;
	printf("Initial disk number:\n");
	scanf("%d", &n);
	steps = move(n, 1, 2, 3);
	printf("Total steps: %d\n", steps);
}
