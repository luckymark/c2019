#include <stdio.h>

int isPrime(int num)
{
    if (num < 2) 
    {
        return 0;
    }
    else if (num == 2)
    {
        return 1;
    }
    else
    {
        for(int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    for(int l = 4; l < 102; l = l + 2)
    {
        for(int k = 1; k <= l/2; k++)
        {
            if ((isPrime( k ))&&(isPrime( l - k )))
            {
                printf("%d = %d + %d\n" ,l ,k ,l-k);
            }
        }
    }
    
    return 0;
}