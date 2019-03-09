#include <stdio.h>
int main()
{
    int num,i,j,a,count;
    int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(num = 4;num < 100;num += 2)
    {
        for(i = 0;primes[i] < num;i++)
        {
            a = num - primes[i];
            count = 0;
            for(j=0;j<25;j++)
            {
                if(a == primes[j])
                {
                    a = primes[j];
                    break;
                }
                else
                    count++;
            }
            if(count<24)
            {
                printf("%-2d = %-2d + %d\n",num,a,primes[i]);
                break;
            }
        }
    }
    printf("\nGoldbach's conjecture is right!\n");
    return 0;
}


