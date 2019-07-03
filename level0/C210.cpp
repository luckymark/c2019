#include<stdio.h>
int main()
{
	int b[5],c[10]={0};
	printf("Please put in 5 numbers(between 0-9):\n");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&b[i]);
		for(int t=0;t<10;t++)
		{
			if(b[i]==t) c[t]++;
		}
	}
	for(int t=0;t<10;t++)
	{
		for(int i=1;i<=c[t];i++)
		{
			printf("%d,",t);
		}
	}
}
