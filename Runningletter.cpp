
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	#define N 80
	for(i=0;i<=N;i++)
	{
      for(j=0;j<i;j++)
	      printf(" ");
	  printf("R");
	  system("cls");
    }
    for(i=N;i>=0;i--)
    {
    	for(j=0;j<=i-1;j++)
    		printf(" ");
		printf("R");
		system("cls");
	}
	return 0;
}
