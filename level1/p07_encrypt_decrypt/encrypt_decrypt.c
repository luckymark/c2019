#pragma warning(disable:4996)
#include<stdio.h>
char str[100000];

void crypt();

int main(void)
{
	printf("Now enter the string you want to encrypt or decrypt.\n");
	crypt(str);
	return 0;
}

void crypt()
{
	int num = 0;
	while ((str[num] = getchar()) != '\n')++num;
	for (int i = 0; i < num; ++i)
	{
		str[i] = 256 - str[i];
		printf("%c", str[i]);
	}
	printf("\n");
}