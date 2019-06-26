#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
void printmap(char *a[30])
{
	int i;
	for(i=65;i<=79;i++)
		{
			printf("%c ",i);
		}
		printf("\n");
		for(i=1;i<30;i++)
		{
			if(i%2==1)
			{
				printf("%s%d\n",a[i],((i+1)/2));
			}
			else
			{
				printf("%s\n",a[i]);
			}
		}
}