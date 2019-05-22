#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <istream.h>
int main(int argc, char *argv[])
{
	char *a[100];
	int i,j,k;
	for(i=0;i<15;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*100);
	}
	FILE *fpRead=fopen("boxmap1.txt","r");
	if(fpRead==NULL)
	{
		return 0;
	}
	for(int i=0;i<15;i++)
	{
		fscanf(fpRead,"%s",a[i]);
		for(j=0;j<20;j++)
		{
			if(a[i][j]=='#')
	        	a[i][j]=' ';
		}
		//if(feof(fpRead))
			printf("%s\n",a[i]);
	}
	return 0;
}
//istream &getline( char *buffer, streamsize num, char delim );