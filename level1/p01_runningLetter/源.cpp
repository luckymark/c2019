#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int LENGTH = 70;
int main()
{
	int k, i = 1, l, p;
	while (i++)
	{
		if (i > LENGTH)l = i % LENGTH;
		else l = i;
		p = i / LENGTH;
		if (p % 2 == 0)
		{
			for (k = 1; k < l - 1; k++)
			{
				printf_s(" ");
			}
			printf_s("->");
		}
		if (p % 2 == 1)
		{
			for (k = 1; k < LENGTH - l - 1; k++) 
			{
				printf_s(" ");
			}
			printf_s("<-");
		}
		Sleep(50);
		system("cls");
	}
	return 0;
}