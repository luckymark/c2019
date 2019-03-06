#include<stdio.h>
#include<time.h>
int main()
{
	long t1,t2;
	t1=clock();
	for(int n=2;n<=1000;n++)
	{
		for(int t=2;t<=n/2+1;t++)
		{
			if(t==n/2+1) printf("%d,",n);
			if(n%t==0) break;
		}
	}
	t2=clock();
	printf("\nTotally used %ld ms.\n",(t2-t1));
}
