#include<stdio.h>
#include<math.h>
int ge(int a);
int shi(int b);
int bai(int c);
int main()
{
	int i;
	for(i=100;i<=999;++i)
		if(i==pow(i%100%10,3)+pow(i/10%10,3)+pow(i/100,3))
			printf("%d\n",i);
	return 0;
}
