#include<stdio.h>
#include<string.h>
char string[1000];
void encrypt(char *s);
void decrypt(char *s);
int main()
{
	gets(string);
	encrypt(string);
	puts(string);
	decrypt(string);
	puts(string);
	return 0;
}
void encrypt(char *s)
{
	int i,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		s[i]=s[i]+1;
	}
	return;
}
void decrypt(char *s)
{
	int i,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		s[i]=s[i]-1;
	}
	return;
}
