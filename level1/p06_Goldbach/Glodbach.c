#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, c;
    int n = 2, primeCount = 0, jump = 0;
    int *primes = (int *)malloc(sizeof(int) * 100);
    while (n <= 100)
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                break;
            }
        }
        i == n && (primes[primeCount] = n, primeCount++);
        n++;
    }
    n = 4;
    while (n <= 100)
    {
        //任一大于2的偶数都可写成两个质数之和
        for (i = 0; i < primeCount && !jump; i++)
        {
            for (c = 0; c < primeCount && !jump; c++)
            {
                if (primes[i] + primes[c]==n)
                {
                    jump = 1;
                    printf("%d is true. %d + %d = %d \n", n, primes[i], primes[c], n);
                }
            }
        }
        !jump && printf("%d is false. \n", n);
        n = n + 2;
        jump = 0;
    }
    return 0;
}