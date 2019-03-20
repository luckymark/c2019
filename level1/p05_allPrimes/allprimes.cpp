#include<stdio.h>
#include<math.h>
#include<time.h>
int main(void)
{
	int temp;
	printf("   2   3");
	for(int i=5;i<=1000;i++)
	{
		temp=sqrt(i);
		for(int j=2;j<=temp;j++)
		{
			if(i%j==0)break;	
			if(j==temp) printf("%4d",i);
		}
		
	}
	printf("\n Time used = %.4f s\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
