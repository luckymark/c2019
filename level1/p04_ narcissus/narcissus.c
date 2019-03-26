#include<stdio.h>

int main()
{
        int a, b, c;    //个位数、十位数、百位数
        int num = 100;        //当前枚举的数

        while(num >= 100 && num <= 999)
        {
                c = num / 100;
                b = num / 10 % 10;
                a = num % 10;

                if(num == a * a * a + b * b * b + c * c * c)
                        printf("%d ", num);

                ++num;
        }
        printf("\n");

        return 0;
}
