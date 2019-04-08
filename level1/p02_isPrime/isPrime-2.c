#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    unsigned long num[65536] = {2}, count = 1, a;

    for (size_t i = 3; i < 65536; i++)
    {
        for (size_t t = 0; t < count; t++)
        {
            if (num[t] * num[t] > i)
                break;
            if (i % num[t] == 0)
                goto Rem;
        }
        num[count] = i;
        count += 1;
    Rem:
        continue;
    }

    for (;;)
    {
        printf("Pleas input a number \n");
        scanf("%d", &a);

        for (size_t i = 0; i < 65536; i++)
        {
            if (a % num[i] == 0)
            {
                printf("%d isn't a prime", a);
                break;
            }
            if (num[i] * num[i] > a)
            {
                printf("%d is a prime", a);
                break;
            }
        }
        printf("\n");
        system("pause");
    }
    return 0;
}