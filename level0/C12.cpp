#include<stdio.h>
int main()
{
	int n;
	printf("Please put in a number:\n");
	scanf("%d",&n);
	if(n%13==0) printf("Yes.\n");
	else printf("No.\n");
}
