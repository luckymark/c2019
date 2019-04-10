#include<stdio.h>
#define WIDTH 119
int main()
{
	int r=0,i=0,j=0;
	while(1)
	{
		for(i=0;i<WIDTH;i++)
		{
		    for(j=0;j<=i;j++)printf(" ");
			printf("R");
			system("cls");
	 	}
	 	for(i=WIDTH-1;i>=0;i--)
		{
	 	    for(j=i-1;j>=0;j--)printf(" ");
			printf("R");
			system("cls");
		}
    }
	return 0;
}
