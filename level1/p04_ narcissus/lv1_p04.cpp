#include<stdio.h>
int main()
{
	int x,g,s,b;
	for(x=100;x<=999;x++)
	{
		g=x%10;
		s=((x-g)/10)%10;
		b=(x-g-s)/100;
		if(x==g*g*g+s*s*s+b*b*b)
		{
			printf("%d£»",x);
		}
	}
	getchar();
}
