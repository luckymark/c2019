#include <stdio.h>
#include <windows.h>
#define MAXLTH 70


void initialize(char ar[], int n);

int main(void)
{
	char str[MAXLTH+1];
	int i;
	
	initialize(str, MAXLTH);
	
	while(1)
	{
			for ( i=0; i<MAXLTH+1; ++i)
			{
				str[i]= 'A';
				printf("\r%s", str);
		
				Sleep(100);
				
				str[i]=' ';
			}
			i -=1;
			for(i; i>-1; --i)
			{
				str[i]= 'A';
				printf("\r%s", str);
		
				Sleep(100);
				
				str[i]=' ';
			}
			
			
	}
	return 0;
}
//function 1
void initialize(char ar[], int n)
{
	int i;
	
	ar[0]= 'A';
	for (i=1; i<n+1; i++)
	{
		ar[i]= ' ';
	}
	ar[i]= '\0';
}
