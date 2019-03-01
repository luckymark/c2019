#include<stdio.h>
#include<math.h>
int ge(int a);
int shi(int b);
int bai(int c);
int main()
{
	int i;
	for(i=100;i<=999;++i)
		if(i==pow(ge(i),3)+pow(shi(i),3)+pow(bai(i),3))
			printf("%d\n",i);
	return 0;
}
int ge(int a)
{
	return a-10*shi(a)-100*bai(a);	//123-10*2-100*3
}
int shi(int b)
{
	b-=100*bai(b);
	return b/10;
}
int bai(int c)
{
	return c/100;
}
