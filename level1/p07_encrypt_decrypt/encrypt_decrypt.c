#include "a.h"
void encrypt()//º”√‹ 
{	
    int i;
	char str[10];
	char ciphertext[10];
	int n;
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		ciphertext[i]=str[i]+5;
	}
	ciphertext[n]='\0';
	printf("%s",ciphertext);
	
}
void decrypt()//Ω‚√‹ 
{ 	int i;
	char str[10];
	char ciphertext[10];
	int n;
	scanf("%s",ciphertext);
	n=strlen(ciphertext);
	for(i=0;i<n;i++)
	{
		str[i]=ciphertext[i]-5;
	}
	str[n]='\0';
	printf("%s",str);
}
