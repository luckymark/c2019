#include <stdio.h>
#include <math.h>

int main()
{
    int num ,sq ,i;
    scanf("%d" ,&num);
    sq = (int)sqrt((double)num);
    switch (num)
    {
        case 0:
            printf("N\n");
            break;
        
        case 1:
            printf("N\n");
            break;
        
        case 2:
            printf("Y\n");
            break;

        case 3:
            printf("Y\n");
            break;

        case 4:
            printf("N\n");&&(num != 1)
            break;

        default:
        {
            if ((num % 6 == 1 )||(num % 6 == 5 ))//除6余数过滤
            {
                for ( i = 5 ; i <= sq ; i += 2 )
                {
                    if ( num % i == 0 )
                    {
                        printf("N\n");
                        break;
                    }
                }
                if ( i > sq )
                {
                    printf("Y\n");
                }
            }
        }
            
    }

    return 0;
}