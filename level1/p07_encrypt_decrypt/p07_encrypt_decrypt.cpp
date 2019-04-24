#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEED 300

int Encrypt(char *a);

void Decrypt(int *b, int x);

char a[128];

int b[128];

char c[128];

int main()
{
	fgets(a, 128, stdin);
	int seed = Encrypt(a);
	printf("After encrypting:");
	int len = strlen(a);
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	Decrypt(b, seed);
	printf("Now we decrypt it: %s\n", c);
	system("pause");
	return 0;
}

int Encrypt(char *a)
{
	int len = strlen(a) - 1;
	srand(time(NULL));
	int seed = rand();
	int i = 0;
	for (i = 0; i < len; i++)
	{
		b[i] = a[i] * (i + 1)*(seed % SEED);
	}
	return seed;
}

void Decrypt(int *b, int x)
{
	int len = strlen(a) - 1;
	int i;
	for (i = 0; i < len; i++)
	{
		c[i] = b[i] / (i + 1) / (x % SEED);
	}
	c[len + 1] = '\0';
}