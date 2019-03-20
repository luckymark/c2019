#include <stdio.h>
#include <math.h>

int main()
{
	for (int age = 0; age <= 200; ++age)
	{
		if (age % 12 == 0 && age % 7 == 0 && age - age / 6 - age / 12 - age / 7 - 5 - 4 == age / 2)
		{
			printf("age = %d\n", age - 4);
			break;
		}
	}
	return 0;
}
