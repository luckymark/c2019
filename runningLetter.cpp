#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define N 80
#define TIME 10
void printl(char c,int x);
int main()
{
	printl('R',0);
	printl('R',1);
	return 0;
}
void printl(char c,int x)
{
	int i,j,k;
	for(i=1;i<=N;i++)
	{
		if(x==0)
			k=i-1;
		else
			k=N-i;
		for(j=1;j<=k;j++)
			printf(" ");
		printf("%c",c);
		Sleep(TIME);
		system("cls");
	}
}
