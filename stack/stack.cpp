#include"dec.h"
char signs[]="+-*/";
int stack[100];
int main()
{
	int i,p=-1;
	char c;
	while((c=getchar())!='\n')
	{
		if(judgesign(c))
		{
			if(c=='+')
			{
				stack[p-1]+=stack[p];
				stack[p]=0;
				--p;
			}
			if(c=='-')
			{
				stack[p-1]-=stack[p];
				stack[p]=0;
				--p;
			}
			if(c=='*')
			{
				stack[p-1]*=stack[p];
				stack[p]=0;
				--p;
			}
			if(c=='/')
			{
				stack[p-1]/=stack[p];
				stack[p]=0;
				--p;
			}
		}
		if(c>='0'&&c<='9')
		{
			stack[++p]=c-'0';
		}
	}
	printf("%d\n",stack[p]);
	return 0;
}
