#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	
	if (n == 1)
	printf("%d is not Prime Number.", n);
	
	else if(n != 1 && n%2!=0 && n%3!=0 && n%5!=0 && n%7!=0)
	printf("%d is Prime Number.", n);
	
	else
	printf("%d is not Prime Number.", n);
	
	return 0;
 } 
