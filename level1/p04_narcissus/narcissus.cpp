#include<stdio.h>
int main(void)
{
	int a,b,c,s;
	printf("narcissistic numbers 100~999\n");
	for (int i=100;i<=999;i++)
	{
		a=i/100;
		b=i/10%10;
		c=i%10;
		s=a*a*a+b*b*b+c*c*c;
		if(s==i) 
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
