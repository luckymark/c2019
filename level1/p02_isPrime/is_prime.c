#include <stdio.h>
#include <math.h>

int test(int n);

int main(void)
{
	int in;

	printf("Enter the integar you want to test:\n");
	scanf("%d", &in);
	
	if( test( in) )
		printf("%d is a prime.\n", in);
	else
		printf("%d is not a prime.\n", in);
		
		
	return 0;
}
//function 1
int test(int n)
{
	int k= sqrt(n);
	int jge, i;
	
	if ( n==1 || n==2)
		jge=0;
	else
		for(i=3; i<k; i++)
			{
				if( n%i==0)
				{
					jge=0;
					break;
				}
				
				jge=1;
			}
			
	return jge;
}
