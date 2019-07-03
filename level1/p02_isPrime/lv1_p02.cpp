#include<stdio.h>
int main()
{
	int n,ans=0;
	printf("Please input a positive integer:\n");
	scanf("%d",&n);
	for(int t=2;t<=n/2;t++)
	{
		if(n%t==0)
		{
			ans=1;
			break;
		}
	}
	if(ans==1) printf("It's not a prime number.");
	else printf("It's a prime number.");
	return 0;
}
