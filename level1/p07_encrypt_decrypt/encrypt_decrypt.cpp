#include<stdio.h>
#include<stdlib.h>
int i,n=0;
char *p;
char c;
void encrypt()
{
	printf("encrypt:\n"); 
	for(i=0;i<=n-1;i++)
	{
		printf("%c",char((int(p[i]))+5));
	}
}
void decrypt()
{
	printf("decrypt:\n");
		for(i=0;i<=n-1;i++)
	{
		printf("%c",p[i]);
	}
}
int main()
{
	printf("Input a string: ");
	p=(char *)malloc(sizeof(char));
	while((c=getchar())!='\n')
	{
		n++;
		p=(char *)realloc(p,n*sizeof(char));
		p[n-1]=c;
	}
	encrypt();
	printf("\n");
	decrypt();
	free(p);
	return 0;
}
