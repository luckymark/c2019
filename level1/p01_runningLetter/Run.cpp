#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define WIDE 80
#define SLEEP 5

void Run(int i);

int main()
{
	system("mode con cols=80 lines=30");
	int i;
	while(true)
	{
		for (i = 1; i < WIDE; i++)
		{
			Run(i);
		}
		for (i; i >= 0; i--)
		{
			Run(i);
		}
	}
	return 0;
}

void Run(int i)
{
	for (int j = 0; j < i; j++)
	{
		printf(" ");
	}
	printf("R");
	Sleep(SLEEP);
	system("cls");
}