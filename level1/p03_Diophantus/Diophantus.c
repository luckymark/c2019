#include<stdio.h>

int main()
{
        int Diophantus_age;
        int childhood, youth, bachelor, before_having_son, between_death, son_age;
        int numerator, denominator;

        //人生中某些阶段占总年龄比例的倒数
        childhood = 6;
        youth = 12;
        bachelor = 7;
        son_age = 2;

        //人生中某些阶段经历的年数
        before_having_son = 5;
        between_death = 4;

        //解方程
        numerator = (before_having_son + between_death) * childhood * youth * bachelor * son_age;
        denominator = childhood * youth * bachelor * son_age
                                - childhood * youth * bachelor
                                - childhood * youth * son_age
                                - childhood * bachelor * son_age
                                - youth * bachelor * son_age;
        Diophantus_age = numerator / denominator;

        printf("%d\n", Diophantus_age - between_death);

        return 0;
}
