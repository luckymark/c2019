#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LENGTH 20

int main ()
{
	int a=0;
	int b=1;
	while(1)
	{
		a+=b;
		system("cls");
		int i=0;
		while(i<a)
		{
			printf(" ");
			i++;
		}
			printf("H");
			Sleep(100);
			if(a==Length)
			{
			   b=-1;
			}
			if(a==0)
			{
				b=1;
			}
	}
    return 0;		
}
	
