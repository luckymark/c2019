#include <stdio.h>
#include <stdlib.h>

char A = 'A';
char B = 'B';
char C = 'C';

void Hanio(char t, int n, char *p);

void SetPosition(char t, int n, char *p);

int main()
{
	int n;
	scanf("%d", &n);
	char *p = (char*)malloc(sizeof(char)*n);
	for (int i = 0; i < n; i++)
	{
		p[i] = A;
	}
	Hanio(C, n, p);
	system("pause");
	return 0;
}

void Hanio(char t, int n, char *p)
{
	if (n > 1)
	{
		SetPosition(t, n, p);
	}
	else
	{
		printf("No.%d %c -> %c\n", n, p[n - 1], t);
		p[n - 1] = t;
	}
}

void SetPosition(char t, int n, char *p)
{
	if (t == A)
	{
		if (p[n - 1] == B)
		{
			Hanio(C, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;			
			Hanio(A, n - 1, p);
		}
		else
		{
			Hanio(B, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;
			Hanio(A, n - 1, p);
		}
	}
	else if (t == B)
	{
		if (p[n - 1] == A)
		{
			Hanio(C, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;
			Hanio(B, n - 1, p);
		}
		else
		{
			Hanio(A, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;
			Hanio(B, n - 1, p);
		}
	}
	else if (t == C)
	{
		if (p[n - 1] == B)
		{
			Hanio(A, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;
			Hanio(C, n - 1, p);
		}
		else
		{
			Hanio(B, n - 1, p);
			printf("No.%d %c -> %c\n", n, p[n - 1], t);
			p[n - 1] = t;
			Hanio(C, n - 1, p);
		}
	}
}