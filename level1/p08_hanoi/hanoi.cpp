#include<cstdio>

void display(int k, int fromP, int toP)
{
	printf("MOV POLE%d, DISK%d from POLE%d\n", toP, k, fromP);
}

int move(int k, int a, int b, int c)    //�ݹ��˼�룬Ҫ�ƶ���k�������Ȱѵ�k-1���ƿ�
{                                       //�������ƶ�n���Ĳ���ΪF(n)����F(n) = F(n-1) + 1 + F(n-1),  F(1) = 1
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
