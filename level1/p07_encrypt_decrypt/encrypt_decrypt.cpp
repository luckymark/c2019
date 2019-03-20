#include<stdio.h>
#include<string.h>
char en (char str);
char de (char str);
int main()
{
	int i, l;
	char str[100], encrypt[100]={'\0'}, decrypt[100]={'\0'};
	printf("Please enter the character string(no spaces): ");
	scanf("%s", &str);
	l = strlen(str);
	
	for(i=0; i<l; i++)                //简单加密 ，只能对不含空格的简单字符串加密 
	{
		encrypt[i] = en(str[i]);
	}
	printf("After the encryption: ");
	printf("%s\n", encrypt);
	
	for(i=0; i<l; i++)                 //解密 
	{
		decrypt[i] = de(encrypt[i]);
	}
	printf("After the decryption: "); 
	printf("%s\n", decrypt);
	
	return 0;
}
char en (char str)
{
	char en;
	en = str + 5;
	return en;
}
char de (char str)
{
	char de;
	de = str - 5;
	return de;
}
