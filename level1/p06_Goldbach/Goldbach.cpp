#include<stdio.h>
#include<math.h>
#define N 100
int prime(int a);
int main()
{
	int j,k,ans,ansall=1;	//ans:judge if j satisfies Goldbach		ansall:judge if all numbers satisfy Goldbach
	for(j=4;j<=N;j+=2)
	{
		ans=0;
		for(k=2;k<=j/2;++k)
			if(prime(k))
				if(prime(j-k))
					ans=1;
		if(ans==0)
			ansall=0;
	}
	if(ansall)
		printf("Correct\n");
	else
		printf("Incorrect\n");
	return 0;
}
int prime(int a)
{
	int i;
	if(i>=4)
		for(i=2;i<=sqrt(a);i++)
			if(a%i==0)
				return 0;
	return 1;
}
