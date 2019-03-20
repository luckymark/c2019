#include<stdio.h>
#include<math.h>
int prime(int num);
int main (void)
{
	int i,n;
	int judge=0;
	for(i=4;i<=100;i=i+2)
	{
		for(n=2;n<=i/2;n++)
		{ 
			if(prime(n)&&prime(i-n))
			{
				printf("%d=%d+%d\n",i,n,i-n);
				judge++;
			}
		}
		if(judge==0)    //判断是否每个数都能分解，若不能分解则结束 
		{
			printf("the law is wrong");
			return 0;
		}	
	} 
	printf("the law is right between 1-100");
	return 0;	
}

int prime(int num)//判断是否是质数 
{
	int temp=sqrt(num);
	if (num==2||num==3) return 1;
	else
	{
		int k;
		for(k=2;k<=temp;k++)
		{
			if(num%k==0) return 0;		
		}
		return 1;
 	}
}
