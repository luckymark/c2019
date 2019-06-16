#include<stdio.h>
#include<math.h>
#include<time.h>
#define N 1000
int main()
{
	int n,m,s;
	int begin,end;
	begin=clock();            //计算开始的时间 
	for(n=2;n<=N;n++)
	{
		s=sqrt(double(n));
		for(m=2;m<=s;m++)
		{
			if(n%m==0)
			  break;
		}
		if(m>s)
		  printf("%d\n",n); 
	}
	end=clock();             //计算结束的时间 
	printf("Calculation time: %dms",end-begin);
	return 0;

}
