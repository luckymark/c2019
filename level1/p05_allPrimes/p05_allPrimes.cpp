#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#define N 2000
bool prime(int n)
{
	int i,k;
	k=1; 
	for(i=2;i<sqrt(n);i++)
	{
		if(n%i==0)
		{
			k=0;
		}
	}
	return k;
}
int main(int argc, char *argv[])
{
	int i,s;
	clock_t start, finish; 
    double Total_time; 
	start = clock(); 
	for(i=2;i<=N;i++)
	{
		if(prime(i)==1)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	finish = clock(); 
	Total_time = (double)(finish-start) / CLOCKS_PER_SEC; 
	printf( "time:%f seconds\n", Total_time); 
	return 0;
}