#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
void createmap(char *a[30])
{
	int i;
	char columnc;
	for(i=1;i<30;i++)
	{
		if(i%2==1)
		{
			columnc=(char)((i+1)/2);
			strcpy(a[i]," | | | | | | | | | | | | | | |");
		}
		if(i%2==0)
		{
			strcpy(a[i],"------------------------------");
		}
	} 
}