#include <stdio.h>
#include <stdlib.h>
#define LENGTH 119
int main(int argc, char *argv[])
{
	int i,j,k;
	for(i=1;i<=LENGTH;i++)
	{
		printf("a");
	    system("cls");
	    for(j=1;j<=i;j++)
	    {
    		printf(" ");
    	}
	}
	for(i=LENGTH;i>=1;i--)
	{
		printf("a");
		system("cls");
		for(j=i;j>=1;j--)
		{
			printf(" ");
		}
	}
	system("cls");
	printf("a");
	system("pause");
	return 0;
}