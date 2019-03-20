#include<stdio.h>
int main()
{
	int num[100]={0};
	int i=0;
	int c;
	while((c=getchar())!='\n')
	{
	getchar();
		if(c=='+')
		{
			num[i-2]=num[i-1]+num[i-2];
			i=i-1;
	
		}
	else if(c=='-')
		{
			num[i-2]=num[i-2]-num[i-1];
			i=i-1;
	
		}
	else if(c=='*')
		{
			num[i-2]=num[i-1]*num[i-2];
			i=i-1;

		}
	else if(c=='/')
		{
			num[i-2]=num[i-1]/num[i-2];
			i=i-1;
		}
		//Îª×ÖÄ¸ 
	else
		{
			num[i]=c-48; 
			i=i+1;
		}

	}
		printf("%d",num[i-1]);
		return 0;
}
