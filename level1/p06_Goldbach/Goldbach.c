#include<stdio.h>
#include<math.h>

int isPrime(int n);
int main()
{
	int n,i,p;
	while(printf("从3~100内输入一个偶数:"),scanf("%d",&n))
	{
		for(i=2;i<=n/2;i++)
		{
			if(isPrime(i)&&isPrime(n-i)) 
			{
				printf("%d, %d\n",i,n-i);
				break;
			}
			
	    } 

    } return 0;
}

int isPrime(int n)
{
	int j;
	
	for(j=2;j<=sqrt(n);j++)
	{
		if(n%j==0) return 0;
		return 1;
	}
	
}
