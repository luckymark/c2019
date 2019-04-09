#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int begintime, endtime;
    int i = 0;
    int a[1002];
    begintime = clock();

    int num[1000] = {2}, count = 1, t;
    printf("2 \n");

    for (size_t i = 3; i < 1000; i++)
    {
        for (t = 0; t < count; t++)
        {
            if (num[t] * num[t] > i)
            {
                num[count++] = i;
                printf("%d \n", i);
                break;
            }
            if (i % num[t] == 0)
            {
                break;
            }
        }
    }

    endtime = clock();
    printf("\n\nRunning Time: %dms\n", endtime - begintime);
    system("pause");
    return 0;
}