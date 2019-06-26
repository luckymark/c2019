#include <stdio.h>
#include <string.h>
#define LENGTH 100000
#define add 3
int encrypt(char c[])
{
	int i;
	for(i=0;i<strlen(c);i++){
		c[i]=c[i]+add;
	}
	return 0;	
}
int decrypt(char c[])
{
	int j;
	for(j=0;j<strlen(c);j++){
		c[j]=c[j]-add;
	}
	return 0;
}
int main()
{
	char c[LENGTH];
	gets(c);
	encrypt(c);
	printf("encrypt as: %s\n",c);
	decrypt(c);
	printf("decrypt as: %s\n",c);	
	return 0;
} 
