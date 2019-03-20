p05
#include<stdio.h>
#include<time.h>
#define maxn 10000000
clock_t start,stop;
double duration;
int p[maxn+5];
int main()
{
	int i,j;
	for(i=2;i<=maxn;i++)
	p[i]=1;
	start=clock();
	for(i=2;i<=maxn;i++)
	{
		if(p[i])
		for(j=2*i;j<=maxn;j=j+i)
		  p[j]=0;
	}
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK;
	for(i=2;i<=maxn;i++)
	if(p[i])
	  printf("%d ",i);
	printf("\nThe time is %lf seconds",duration);
	return 0;
}
