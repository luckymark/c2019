//在100范围内验证哥德巴赫猜想的正确性
//原初猜想的现代陈述：任一大于5的整数都可写成三个质数之和

#include<stdio.h>
#define N 100         //上界
#define M 6           //下界

int main()
{
        int i, j1, j2, j3;
        int prime[50] = {0};            //用于存放100以内的质数
        void Prime(int prime[]);        //把100以内的素数存放到prime数组里

        Prime(prime);

        for(i = M; i <= N; ++i)
        {
                //如果验证了当前数符合哥德巴赫猜想，就跳到最外层循环的末尾
                for(j1 = 0; prime[j1] <= (i - 4); ++j1)
                        for(j2 = j1; prime[j2] <= (i - 4); ++j2)
                                for(j3 = j2; prime[j3] <= (i - 4); ++j3)
                                        if(i == prime[j1] + prime[j2] + prime[j3])
                                                goto sf;

                //如果没有跳到末尾，则当前数不符合哥德巴赫猜想，输出"Error!"，终止程序并返回“1”
                printf("Error!\n");
                return 1;

                sf:
                        ;
        }

        printf("Goldbach conjecture within 100 is verified.\n");
        return 0;
}

void Prime(int prime[])
{
        int i, j;
        int num;                        //当前检索的数

        prime[0] = 2;
        i = 0;
        num = 2;

        while(++num <= N)
        {
                for(j = 0; prime[j]; ++j)
                {
                        if(num % prime[j] == 0)
                                break;
                }

                if(prime[j] == 0)
                        prime[j] = num;
        }

        //这段用来测试，完成后删去
        j = -1;
        while(prime[++j])
        {
                printf("%5d ", prime[j]);

                if((j + 1) % 10 == 0)
                        printf("\n");
        }
        printf("\n\n");
}
