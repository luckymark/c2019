#include<stdio.h>
#include<windows.h>
#define length 117
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