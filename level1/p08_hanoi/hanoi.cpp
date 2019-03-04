#include<stdio.h>
char a='A',b='B',c='C';
void change(int n,char p,char q,char m)
{
	if(n==1)
	{
		printf("The 1 has been moved from %c to %c.\n",p,q);
	}
	else
    {
    	change(n-1,p,m,q);
    	printf("The %d has been moved from %c to %c.\n",n,p,q);
    	change(n-1,m,q,p);
	}
} 
int main()
{
	int n;
	printf("The number: ");
	scanf("%d",&n);
	change(n,a,b,c);
	return 0;
}
