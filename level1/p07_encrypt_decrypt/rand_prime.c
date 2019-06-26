//随机返回质数

#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef unsigned long UL;

UL rand_prime()
{
        int num;        //随机生成的数
        int i;          //循环体内的计数变量
        int mark;       //mark为1表示当前数是质数

        for(;;)
        {
                //随机生成一个数
                srand((unsigned)time(NULL));
                num = 2 * rand() - 1;

                //判断当前数是否为质数
                mark = 1;
                for(i = 2; i <= sqrt(num); ++i)
                {
                        if(num % i == 0)
                        {
                                mark = 0;
                                goto a;
                        }
                }

                a:
                if(mark == 1)
                {
                        return num;
                }
        }
}
