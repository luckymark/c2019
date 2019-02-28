#include<stdio.h>
#include<math.h>
int prime(int a);
int main()
{
	int n;
	printf("Please input an integer:");
	scanf("%d",&n);
	if(n<4)
		if(n<=1)
			printf("No\n");
		else
			printf("Yes\n");
	else
		if(prime(n))
			printf("Yes\n");
		else
			printf("No\n");
}
int prime(int a)
{
	int i;
	for(i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return 0;
	return 1;
}
