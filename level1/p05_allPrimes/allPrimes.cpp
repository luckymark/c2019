#include<stdio.h>
#include<time.h>
int main()
{
	int i,j;
	clock_t start, end;
	
	start= clock();
	
	for(i=2; i<=1000; i++)
	{
		for(j=2; ; j++)
		{
			if(i%j==0)
			break;
		}
		
		if(j>=i)
		printf("%d ", i);
	}
	
	end= clock();
	
	printf("\nTotal computation time: %f seconds.", (double)(end-start)/CLOCKS_PER_SEC);
	
	return 0;
} 
