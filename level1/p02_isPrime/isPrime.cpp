#include<stdio.h>
#include<math.h>
int main()
{
	int i,n,j,s;
	printf("Please input a positive integer amd I will tell you whether it is a prime: ");
	scanf("%d",&n);
	s=sqrt(double(n));
	for(i=2;i<=s;i++)
	{
		j=n%i;
		if(j==0)
		  break;
	}
	if(i>s)
	    printf("%d is a prime.",n);
	else
	    printf("%d is not a prime.",n);
	return 0;
}
