#include <stdio.h>
#include <string.h>
#define LENGTH 100000
//此加密方法为将字符串ASCII码+5 
int encrypt(char s[])
{
	int a[LENGTH];
	int i;
	for(i=1;i<=LENGTH;i++)
	{
		a[i]=-1;
	}
	for(i=0;i<strlen(s);i++)
	{
		a[i]=s[i];
	}
	for(i=0;i<strlen(s);i++)
	{
		if(a[i]!=-1)
		{
			a[i]=a[i]+5;
		}
	}
	for(i=0;i<strlen(s);i++)
	{
		s[i]=(char)a[i];
	}
	return 0;
}
int decrypt(char s[])
{
	int b[LENGTH];
	int x;
	for(x=1;x<=LENGTH;x++)
	{
		b[x]=-1;
	}
	for(x=0;x<strlen(s);x++)
	{
		b[x]=s[x];
	}
	for(x=0;x<strlen(s);x++)
	{
		if(b[x]!=-1)
		{
			b[x]=b[x]-5;
		}
	}
	for(x=0;x<strlen(s);x++)
	{
		s[x]=(char)b[x];
	}
	return 0;
}
int main(int argc, char *argv[])
{
	char s[LENGTH]="null";
	int i;
	scanf("%[^\n]",s);
	encrypt(s);
	printf("加密后：%s\n",s);
	decrypt(s);
	printf("解密后：%s\n",s);
	return 0;
}