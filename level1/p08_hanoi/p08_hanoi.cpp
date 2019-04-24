#include <stdio.h>
#include <stdlib.h>

char A = 'A';
char B = 'B';
char C = 'C';

void Hanio(int n, char A, char B, char C);


int main()
{
	int n;
	scanf("%d", &n);
	Hanio(n, A, B, C);
	system("pause");
	return 0;
}

void Hanio(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("No.%d %c -> %c\n", n, A, C);
	}
	else
	{
		Hanio(n - 1, A, C, B);
		printf("No.%d %c -> %c\n", n, A, C);
		Hanio(n - 1, B, A, C);
	}
}