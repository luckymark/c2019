#include<stdio.h>
#include<math.h>
int main()
{
	int i, n=3;
	int a, b, c;
	
	printf("All the narcissistic number: ");
	
	for(i=100; i<=999; i++)
	{
		a = i/100;
		b = (i/10)%10;
		c = i%10;
		
		if( pow(a,n) + pow(b,n) + pow(c,n) == i)
		printf("%d ", i);
	}
	
	return 0;
 } 
