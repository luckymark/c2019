#include<stdio.h>
#include<stdlib.h>

double Form(double x);

int main()
{
	double x = 10;
	while (true)
	{
		if (Form(x) == x)
		{
			printf("Diophantus is %d years old when his son died.", (int)x-4);
			system("pause");
			return 0;
		}
		x++;
	}
}

double Form(double x)
{
	double y = x / 6 + x / 12 + x / 7 + 5 + x / 2 + 4;
	return y;
}