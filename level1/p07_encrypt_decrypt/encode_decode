#include<stdio.h>
#include<string.h>

void encode(char str[],int n); 
void decode(char str[],int n);

int main()
{
	char str[2048];
	int n; 
	int choice;
	printf("请输入一段字符：");
	scanf("%s",&str);
	printf("加密字符请输入1\n");
	printf("解密字符请输入2\n");
	printf("请输入你的选择；");
	scanf("%d",&choice);
	
	if(choice==1)
	{
		printf("请输入一个数字选择加密方式：");
		scanf("%d",&n); 
	} 

	switch(choice)
	{
		case 1:
			encode(str,n);
			break;
			
		case 2:
			decode(str,n);
			break;
	}
	return 0;
}

void encode(char str[],int n)
{
	char ch;
	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i]+=n;
	}
	printf("加密后的字符为：%s",str);
}

void decode(char str[],int n)
{
	char ch;
	int i;
	for(i=0;i<strlen(str);i++)
	{
		str[i]-=n;
	}
	printf("解密后的字符为：%s",str);
	
}
