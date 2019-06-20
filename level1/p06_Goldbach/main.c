#include <stdio.h>
#include <stdlib.h>

int result(int n);

int main()
{
    int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int i,j,n;
    for(n=4;n<=100;n+=2){
        for(i=0;i<=24;i++){
            for(j=0;j<=24;j++){
                if(prime[i]+prime[j]==n)
                    printf("%d + %d = %d\n",prime[i],prime[j],n);
                else continue;
            }
        }
    }
    return 0;
}



