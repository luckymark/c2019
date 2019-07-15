#include<stdio.h>
int main()
{
    int hun,dec,uni,med,nar;
    for(med=100;med<=999;med++)
    {  	
        hun=med/100;
        dec=(med-(hun*100))/10;
        uni=(med-(hun*100)-dec*10);
        nar=hun*hun*hun+dec*dec*dec+uni*uni*uni;
        if (nar==med)
        {
			printf("%d ",nar);
		}
    }
    printf("\n");
} 
