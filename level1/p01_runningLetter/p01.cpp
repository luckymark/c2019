#include <iostream>
#include <Windows.h>
#include <cstring>
#include <conio.h>

void print_space(int n);

int main()
{
	const int SLEEP_TIME = 100;
	const int CMD_SIZE = 80;
	const char str[] = "njjnb";

	int space_n = 0;
	int space_max = CMD_SIZE - strlen(str);
	int add = 1;

	while (1)
	{
		print_space(space_n);

		printf("%s", str);

		if (space_n == 0)
			add = 1;
		else if (space_n == space_max)
			add = -1;
		space_n += add;

		Sleep(SLEEP_TIME);
		system("cls");

	}
}

void print_space(int n)
{
	for (int i = 0; i < n; i++)
		printf(" ");
}
