#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,wide=80;
	bool turn;
	for(i=0;;)
	{
		for(int t=0;t<=i;t++)
		{
			printf(" ");
		}
		printf("R");
		system("cls");
		if(i==wide) turn=1;
		if(i<0) turn=0;
		if(turn==0) i++;
		else i--;
	}
} 
