#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
	int year=100;
	double temp;
	
	while (1)
	{
		temp=year*75.0/84.0+9.0;
		
		if (temp==year)
			break;
		else 
			year=temp;
	}
	
	printf("%d", year);
	
	return 0;
}