#include<stdio.h>
int main()
{
	int n; //The amount of years the father lived
	for(n=1;n>0;n++)
	{
	 if((n/6+n/12+n/7+5+n/2+4)==n&&n%12==0&&n%7==0)
	    {
		 printf("He is %d years old when his son died.",n-4);
	     break;
	    }
    }
	return 0;
}
