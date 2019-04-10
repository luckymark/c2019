#include <stdio.h>
#include <math.h>

//最大检查到平方根即可

int main()
{
    int num ,sq ,i;

    scanf("%d" ,&num );

    sq = (int)sqrt((double)num);//类型转换
    num = (num == 1) ? 0: num;//制作num为1时的特例

    if ((num % 6 == 1 )||(num % 6 == 5 ))//除6余数过滤
    {
        for ( i = 5 ; i <= sq ; i += 2)
        {
            if (num % i == 0)
            {
                printf("N\n");
                break;
            }
        }
        if (i > sq)
        {
            printf("Y\n");
        }
    }
    else
    {
        switch (num)
        {   
            case 2:
                printf("Y\n");
                break;

            case 3:
                printf("Y\n");
                break;
        
            default:
                printf("N\n");
                break;
        }
    }
    
    return 0;
}