#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int num[100] = {2}, count = 1, t;

    for(size_t i = 3; i < 100;)
    {
        for(t = 0; t < count; t++)
        {
            if (num[t] * num[t] > i) break;
            if (i % num[t] == 0) goto Rem;
        }
        num[count] = i;
        count += 1;
        Rem:i++;
    }
    for(size_t i = 4; i < 102; i += 2)
    {
        for(size_t a = 0; a < 25; a++)
        {
            for(size_t b = 0; b < 25; b++)
            {
                if (i == num[a] + num[b]) {
                    printf("%d=%d+%d \n", i, num[a], num[b]);
                    a = 25;
                }
            }
        }
    }
    system("pause");
    return 0;
}
