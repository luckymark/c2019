#include<stdio.h>
#define N 64
void hanoi(int n,char s1,char s2,char s3);			//move n lawers from s1 to s3 with s2 in between
int main()
{
	hanoi(N,'A','B','C');
	return 0;
}
void hanoi(int n,char s1,char s2,char s3)
{
	if(n==1)
		printf("%c=>%c\n",s1,s3);
	else
	{
		hanoi(n-1,s1,s3,s2);
		printf("%c=>%c\n",s1,s3);
		hanoi(n-1,s2,s1,s3);
	}
}
