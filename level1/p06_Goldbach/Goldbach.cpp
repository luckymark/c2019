#include<stdio.h>
int main()
{
	int i, j, k=0, n;
	
	int Primes[25];
	
	for(i=2; i<=100; i++)              //先找出100以内的素数// 
	{
		for(j=2; ; j++)
		{
			if(i%j==0)
			break;
		}
		if(j>=i)
		{
			Primes[k] = i;
			k++;
		}
	}
	
	for(i=4; i<=100; i=i+2)            //验证偶数的哥德巴赫猜想// 
	{
		for(j=0; j<=24; j++)
		{
			for(k=0; k<=24; k++)
			{
				if(i == Primes[j]+Primes[k] )
				goto ODD;
			}
		}
		ODD: printf("%d = %d+%d\n", i, Primes[j], Primes[k]);
	}
	
	for(i=5; i<=100; i=i+2)            //验证奇数的哥德巴赫猜想// 
	{
		for(j=0; j<=24; j++)
		{
			for(k=0; k<=24; k++)
			{
				for(n=0; n<=24; n++)
				{
					if(i == Primes[j]+Primes[k]+Primes[n] )
					goto EVEN;
				}
			}
		}
		EVEN: printf("%d = %d+%d+%d\n", i, Primes[j], Primes[k], Primes[n]);
	}
	return 0;
}
