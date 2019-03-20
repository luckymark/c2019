#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

const int LENGTH = 100;

int main()
{
	int n,j,w,k;
	int i = 1;
	char ch = 's';
	for(n=LENGTH;i<=n;i++)
	{
		printf("%c",ch);
		system("cls");
		Sleep(100);
		
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
	}
	for(k=1;k<=LENGTH;k++)
	{
		for(w=LENGTH;w>=k;w--)
		{
			printf(" ");
		}
		
		printf("%c",ch);
		system("cls");
		Sleep(100);
	}
	return 0;
}
