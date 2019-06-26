//打印2~1000以内的所有素数
//打印出总的计算时间
//尽可能地优化算法的效率

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
        int n = 2;              //当前检索的数
        int prime[200] = {0};   //用于存放找到的素数
        int i;

        clock_t start, finish;
        double duration;
        //测量一个事件的持续时间

        start = clock();        //计时开始

        prime[0] = 2;

        //若已检索出的任何一个素数都不是当前检索的数的因子
        //那么当前检索的数是素数
        while(++n <= 1000)
        {
                for(i = 0; prime[i]; ++i)
                {
                        if(n % prime[i] == 0)
                                break;
                }

                if(prime[i] == 0)
                        prime[i] = n;
        }

        finish = clock();       //计时结束
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        //打印检索到的素数
        i = -1;
        while(prime[++i])
        {
                printf("%5d", prime[i]);

                //每15个素数输出为一行
                if((i + 1) % 15 == 0)
                        printf("\n");
        }

        //打印总的计算时间
        printf("\n\nTime to calculate all primes is %f seconds.\n", duration);

        return 0;
}
