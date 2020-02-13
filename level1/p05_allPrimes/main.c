#include<stdio.h>
#include<math.h>
#include<time.h>
#include"prime_under_1000.h"

int main()
{
	int i,w;//i from 1 to 1000;w=return value 
	time_t begin,end;
	
	begin=clock();
	
	printf("2");//other primes are all odd
	for(i=3;i<=1000;i+=2)
	{ 
		if (prime(i)==0)
		{
			printf(",%d",i);	
		} 
	}
	
	end=clock();
	printf("\n\nTime used=%dms",end-begin);
	return 0;
}
