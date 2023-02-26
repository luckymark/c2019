#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
       clock_t start, finish;
       double cost;
       int i,j;
       start=clock();
       printf("allPrimes:\n\n2  3  5  7  ");
       for(i=5;i<1000;i += 2)
       {
           int count = 3;
           for(j=3;j<i;j++)
           {
               if(i%j==0||i%3 == 0||i% 5==0||i%7==0)
                break;
               else
                count++;
           }
           if(i == count)
            printf("%-3d ",i);
       }
       printf("\n\n");
       finish = clock();
       cost = (double)(finish-start)/CLOCKS_PER_SEC;
       printf("cost time : %lfs",cost);
    return 0;
}
