#include<stdio.h>
int is_p(int x)
{
	for(int i=2;i<=x/2+1;i++)
	{
		if(i==x/2+1) return 1;
		if(x%i==0)
		{
			return 0;
			break;
		}
	}
}

int main()
{
	int prime;
	for(int t=4;t<101;t=t+2)
	{
		int m=2,n;
		for(;;)
		{
			prime=is_p(m);
			if(prime==1)
			{
				n=t-m;
				prime=is_p(n);
				if(prime==1) 
				{
					printf("%d=%d+%d\n",t,m,n);
					break;
				}
			}
			m++;
		}
	}
}
