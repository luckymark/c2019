#include<stdio.h>
#include<windows.h> 
#define len 120
int main(void)
{
	while (1)
	{
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < i; ++j)
				printf(" ");
			printf("C");
			system("cls");
			Sleep(10);
		}

		for (int i = 0; i < len; ++i)
		{
			for (int j = len - 1; j > i; --j)
				printf(" ");
			printf("C");
			system("cls");
			Sleep(10);
		}

	}

	return 0;
}