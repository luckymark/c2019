p02
#include<stdio.h>
int main()
{
	int n,i;
	int first=1;
	scanf("%d",&n);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0){
			first=0;
			break;
		}
	}
	if(first)
	   printf("n is a prime.");
	else
	   printf("n is not a prime.");
	return 0;
}
