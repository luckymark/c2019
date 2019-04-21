#include<stdio.h>
#include<math.h>
int main(void)
{
	int temp,x,i;
	printf("input a number to determine whether it is a prime number.\n");
	scanf("%d",&x);
	temp=sqrt(x);
	for(i=2;i<=temp;i++)
	{
		if(x%i==0)
		{
			printf("%d is not a prime number",x);
			return 0;
		}	
	}
	printf("%d is a prime number",x);
	return 0;	
}
