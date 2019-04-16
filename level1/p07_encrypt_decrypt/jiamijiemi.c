#include<stdio.h>
#define LENGTH 500

int main() 
{
	char text[LENGTH];
	
	printf("Please choose the operation you want:\nEnter E to encrypt\nEnter D to decrypt\n");
	char choice=getchar();
	if(choice=='E')
	{
		printf("Please enter the text needs to be encrypted:\n");
		scanf("%s",&text);
		for(int i=0;i<strlen(text);++i)
		{
			text[i]+=1;
		}
		printf("%s",text);
	
	}
	if(choice=='D')
	{
		printf("Please enter the text needs to be decrypted:\n");
		scanf("%s",&text);
		for(int i=0;i<strlen(text);++i)
		{
			text[i]-=1;
		}
		printf("%s",text);
	}
	return 0;
}
