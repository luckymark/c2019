#include <stdio.h>
#include <math.h>

int main()
{
    int u = 0, t = 0, h = 1;
    while (h != 10)
    {
        if (pow(u, 3) + pow(t, 3) + pow(h, 3) == u + t * 10 + h * 100)
        {
            printf("%d%d%d\n", h, t, u);
        }
        u++;
        if (u == 10)
        {
            u = 0;
            t++;
            if (t == 10)
            {
                t = 0;
                h++;
            }
        }
    }
    return 0;
}