#include <stdio.h>
#include <stdlib.h>

void NotPrime();

int main()
{
	int i;
	scanf("%d", &i);
	if (i == 1)
	{
		NotPrime();
	}
	for (int n = 2; n*n <= i; n++)
	{
		if (i%n == 0)
		{
			NotPrime();
			return 0;
		}
	}
	printf("This is a Prime.");
	system("pause");
	return 0;
}

void NotPrime()
{
	printf("This is not a Prime!!!");
	system("pause");
<<<<<<< HEAD
}
=======
}
>>>>>>> 2b6d759c8e10cfe17d315e90703734d5f6ddb2ff
