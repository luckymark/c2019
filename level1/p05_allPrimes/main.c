#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    clock_t t1,t2;
    t1=clock();
    int i,n;
    int a[]={2,3,5,7,11,13,17,19,23,29,31,37};
    printf("2,3,5,7,11,13,17,19,23,29,31,37,");
    for(n=2;n<1000;n++)
    {
        int b=0;
        for (i=0;i<12;i++)
        {
            if(n%a[i]==0)
            {
                b++;
            }
        }
        if(!b)
            printf("%d,",n);
    }
    printf("\n");
    t2=clock();
    printf("time is %ld ms",t2-t1);

}
