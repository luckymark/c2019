#include <stdio.h>

int main()
{
    int num;

    scanf("%d" ,&num);

    if (num < 2)
    {
        printf("N\n");
    }
    else if (num == 2)
    {
        printf("Y\n");
    }
    
    else
    {
        for(int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                printf("N\n");
                break;
            }
            else if (i == num)
            {
                printf("Y\n");
                break;
            }
        }
    }

    return 0;
}