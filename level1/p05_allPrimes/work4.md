#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    int i,j,sqr,k ;
    clock_t  start,finish;
    double total;
    printf("2\n3\n");
    start = clock();
    for(i=5;i<=1000;i = i+2)
    {
        k = 0;
        sqr = sqrt(i);
        for(j =2;j<=sqr;j++)
        {
            if(i%j == 0)
            {
            k++;
            }
        }
        if(k == 0)
        {
            printf("%d\n",i);
        }
    }
    finish = clock();
    total = (double)(finish - start);
    printf("the total time is %f seconds",total);
    return 0;
}
