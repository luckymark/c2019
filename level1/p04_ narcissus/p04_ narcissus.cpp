#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i,a,b,c,n;
	printf("3位水仙花数：\n"); 
	for(i=100;i<=999;i++)
	{
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%d=%d^3+%d^3+%d^3\n",i,a,b,c);
	}
	system("pause");
	return 0;
}