#include <stdio.h>
#define MAX_RANGE /*(2 << 29 - 1)*/ 100000
int main()
{
    int n;
    int funCode = 1; //zero is allPrimes,one is isPrime
    while (scanf("%d", &n) == 1 && n > 1)
    {
        int A[MAX_RANGE] = {0}; //Use zero to represent this is a prime.Use one to represent this is a prime.
        int num = 0;
        int TempOfPrime[MAX_RANGE];
        for (int i = 2; i <= n; i++)
        {
            if (!A[i])
            {
                num += 1;
                TempOfPrime[num] = i; //Attention:First element is a[1]
            }
            for (int j = 1; j <= num&&i*TempOfPrime[j]<=n; j++)
            {
                A[i * TempOfPrime[j]] = 1;
                if ((i % TempOfPrime[j])==0)
                    break;
            }
        }
        if (!funCode)
        {
            for (int i = 2; i <= n; i++)
                if (!A[i])
                    printf("%d ", i);
        }
        else
        {

            (!A[n]) ? printf("%d is prime ", n) : printf("%d is not prime ", n);
        }
    }
}