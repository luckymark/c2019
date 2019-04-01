#include<stdio.h>
#include<math.h>
#include<time.h>

clock_t start, stop;
double duration;

int main()
{
	start = clock();
	
	int num[999];
	for(int i=0;i<999;++i)//为每个数匹配一个状态，起初默认均为素数（1） 
	{
		num[i]=1;
	}
	for(int shu=2;shu<=1000;++shu)//对每个数进行判断 
	{
		if(1==num[shu-2])// 如果还未被判断不是素数 (0)
		{
			for(int q=sqrt(shu);q>1;--q)//暴力判断此数是否为素数 
			{
				if(0==shu%q)//如果不是素数，标记状态（0） 
				{
					num[shu-2]=0;
				}
			}
			if(1==num[shu-2])//如果此数为素数 
			{
				for(int i=2;shu*i<=1000;++i)//标记此素数的倍数为非素数（0） 
				{
					num[shu*i-2]=0;
				}
			}
		}
	}
	for(int i=0;i<999;++i)//对每个数，如果是素数（1）则输出 
	{
		if(1==num[i])
		printf("%d\n",i+2);
	}
	
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("运行时间为%fs\n",duration);
	
	return 0;
}
