#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i,n,k;
	k=1;
	loop:scanf("%d",&n);
	if(n<=0)
	{
		printf("请输入一个正整数\n"); 
		goto loop;
	}
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			k=0;
		}
	}
	if(k==0||n==1||n==2)
	{
		printf("不是素数\n"); 
	}
	else 
	   printf("是素数\n");
	   system("pause");
	return 0;
}