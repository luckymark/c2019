/*Caesar encrypt and decrypt(Now lower case only)*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define CN 5
int main()
{
	char c,*ins;
	int i=0;
	ins=(char *)malloc(1);
	while((c=getchar())!='\n')
	{
		ins[i]=c;
		++i;
		ins=(char *)realloc(ins,i+1);
		ins[i]='\0';
	}
	printf("encrypt:");
	for(i=0;i<strlen(ins);++i)
	{
		if(ins[i]+CN>'z')
			putchar(ins[i]+CN-26);
		else
			putchar(ins[i]+CN);
	}
	printf("\ndecrypt:");
	for(i=0;i<strlen(ins);++i)
		putchar(ins[i]);
	printf("\n");
	return 0;
}
