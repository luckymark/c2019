#include<stdio.h>
#include<math.h>

int main()
{
	int n,k,i;
	printf("Please input a number:");
	scanf("%d",&n);
	k = sqrt(n);

	if(n==1)
		printf("%d is not a prime number.",n);
	else if(n==2)
		printf("%d is a prime number.",n);
	else
	{
		for(i=2;i<=k;i++)
	{
		if(n%i==0)
		break;
	}
		if(i>k)
			printf("%d is a prime number.",n);
		else 
			printf("%d is not a prime number.",n);
	}

	return 0;
}
