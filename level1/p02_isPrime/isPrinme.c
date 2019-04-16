#include<stdio.h>
#include<math.h>
int main()
{
	int n,flag=1;
	
	scanf("%d",&n);
	if(n<=1) 
	{
		printf("%d不是素数\n",n);
		flag=0;
	}
	if(n%6!=1&&n%6!=5&&n>6)//如果n大于6且不与6的倍数为邻 ,n不是素数 
	printf("%d不是素数\n",n);
	else 
	{
		for(int a=sqrt(n);a>=2;--a)
		{
			if(n%a==0)
			{
				printf("%d不是素数\n",n);
				flag=0;
				break;
			}
		}
		if(flag)
			printf("%d是素数\n",n); 
	}
	
	return 0;
}
