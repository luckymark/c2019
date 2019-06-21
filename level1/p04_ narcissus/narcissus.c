p04
#include<stdio.h>
int trisum(int n)
{
	int a,b,c;
	a=n%10;
	b=(n/10)%10;
	c=n/100;
	return a*a*a+b*b*b+c*c*c;
}
int main()
{
	int a,b,c,i;
	for(i=100;i<1000;i++)
	{
		if(i==trisum(i))
		printf("%d\n",i);
	}
	return 0;
}
