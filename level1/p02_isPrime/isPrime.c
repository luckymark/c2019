#include <stdio.h>

int main()
{
    int num, i;
    int isPrime = 1;
    printf("Enter a number:");
    scanf("%d", &num);
    num == 1 && (isPrime = 0);
    for (i = 2; i < num - 1; i++)
    {
        if (num % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    printf("%d is%s a prime number. ", num, isPrime == 1 ? "" : "n't");
    return 0;
}