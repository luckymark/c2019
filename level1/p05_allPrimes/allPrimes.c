#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

int main()
{
    clock_t t1 = clock();
    int i, t;
    int n = 2;
    while (n <= 1000)
    {
        for (i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                break;
            }
        }
        i == n &&printf("%d\n", n);
        n++;
    }

    clock_t t2 = clock();
    double ts = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("execution time: %fs\n", ts);
    return 0;
}