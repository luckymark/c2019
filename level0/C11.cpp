#include<stdio.h>
int main()
{
	int n;
	printf("Please put in a number:\n");
	scanf("%d",&n);
	if(n%2==0) printf("It's an even number.\n");
	else printf("It's an odd number.\n");
	if(n>0) printf("It's a positive number.\n");
	else if(n==0) printf("It's zero.\n");
	else printf("It's a negative number.\n");
}
