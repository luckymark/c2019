#include<stdio.h>
int main()
{
	int x,a,b,c;
	printf("Narcissistic numbes between 100~999 are as follows:");
	for(x=100;x<=999;x++)
	{
		a=x/100;
		b=(x-a*100)/10;
		c=x%10;
		if(a*a*a+b*b*b+c*c*c==x)
		{
			printf(" %d",x);
		}	
	}
	return 0;
}
