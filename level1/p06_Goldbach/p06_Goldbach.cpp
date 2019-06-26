#include <stdio.h>
#include <math.h>
bool prime(int n)
{
	int i,k;
	k=1;
	for(i=2;i<sqrt(n);i++)
	{
		if(n%i==0)
		{
			k=0;
		}
	}
	return k;
}
int main(int argc, char *argv[])
{
	int i,j,t,n,s;
	for(i=4;i<=100;i=i+2)
	{
		for(j=2;j<i;j++)
		{
			if((prime(j)==1)&&(prime(i-j)==1))
			{
				printf("%d=%d+%d\n",i,j,i-j);
			}
		}
	}
	return 0;
}