#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define LENGTH 117
int main()
{
	int flag=0,a=0;
	
	while(1)
	{
		for(int i=a;i>0;--i)
		printf(" ");
		
		printf("Van");
		Sleep(70);
		system("cls");
		
		if(a==0)
		flag=0;
		if(a==length)
		flag=1;
		
		if(flag)
		--a;
		else
		++a;
	}
	
	return 0;
}
