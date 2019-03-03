#include<stdio.h>
#include<time.h>
#include<math.h>
#define N 1000
int prime(int a);
int main()
{
	int i,t1,t2;
	t1=clock();
	for(i=2;i<=N;++i)
		if(prime(i))
			printf("%d\n",i);
	t2=clock();
	printf("Working time:%dms\n",t2-t1);
	return 0;
}
int prime(int a)
{
	int j;
	if(a>=4)
		for(j=2;j<=sqrt(a);++j)
			if(a%j==0)
				return 0;
	return 1;
}
