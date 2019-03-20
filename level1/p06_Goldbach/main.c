#include<stdio.h>
#include<math.h>
#include"Goldbach.h"

int main()
{
	int i;
	for(i=4;i<=100;i+=2)
	{
		Goldbach(i);
		printf("\n");
	}
	return 0 ;
} 
