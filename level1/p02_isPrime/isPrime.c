#include<stdio.h>
#include<math.h>

int main()
{
        int n;
        int i;

        scanf("%d", &n);

        for(i = 2; i <= sqrt(n); ++i)
        {
                if(n % i == 0)
                {
                        printf("%d is not a prime.\n", n);
                        return 0;
                }
        }

        //1不是素数
        if(n == 1)
        {
                printf("1 is not a prime.\n");
                return 0;
        }

        printf("%d is a prime.\n", n);

        return 0;
}
