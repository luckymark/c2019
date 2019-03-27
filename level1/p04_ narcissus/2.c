#include<stdio.h>
#include<math.h>
#define max 3

int pick(int x);

int main()
{
	int all=0;
	for(int x=100;x<1000;++x)
	{
		for(int i=0;i<max;++i)
		all+=(int)pow((int)(x/pow(10,i))%10,max);
		if(x==all)
		printf("%d	",x);
		all=0;
	}
	
	return 0;
}
