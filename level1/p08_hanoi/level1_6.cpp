#include<stdio.h>

void hanoi(int n,char a,char b,char c)
{

	if(n==1)
	{
		printf("%c->%c\n",a,c);
	}
	else
	{
		hanoi(n-1,a,c,b);
		printf("%c->%c\n",a,c);
		hanoi(n-1,b,a,c);
	}
}

int main()
{
	int n=4;
	hanoi(n,'A','B','C');
	return 0;
}
