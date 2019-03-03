#include<stdio.h>
#include<stdlib.h>
#define WIDTH 100
int main()
{
	int i, j;
	
	for(i=0; i<=WIDTH; i++)
	{
		for(j=0; j<i; j++)
		{
			printf(" ");
		}
		
		printf("B");
		system("cls");
	}
	
	for(i=100; i>=0; i--)
	{
		for(j=0; j<i; j++)
		{
			printf(" ");
		}
		
		printf("B");
		system("cls");
	}
	
	return 0;
 } 
