#include<stdio.h>
#include<stdlib.h>
//isprime 
int main()
{
	int i,n;
	printf("enter a number: ");
	scanf("%d",&n);
	for(i=2;i*i<=n;i++){
		if(n%i==0)
		break;
	} 
	if(i*i>n)
		printf("prime");
	else
		printf("not prime")	;
	return 0;
}