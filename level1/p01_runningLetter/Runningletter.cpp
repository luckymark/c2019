
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	#define WIDTH 80              
	for(i=0;i<=WIDTH;i++)
	{
      for(j=0;j<i;j++)
	      printf(" ");
	  printf("R");
	  system("cls");
    }
    for(i=WIDTH;i>=0;i--)
    {
    	for(j=0;j<=i-1;j++)
    		printf(" ");
		printf("R");
		system("cls");
	}
	return 0;
}
