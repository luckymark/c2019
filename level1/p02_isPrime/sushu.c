#include <stdio.h>
int main()
{
    int num,i,count = 0;
    printf("input a number:");
    scanf("%d",&num);
    if(num <= 0)
    {
        printf("error!input again:");//重新输入一个正整数
        scanf("%d",&num);
    }
    else if(num == 1)
    {
        printf("N");                 //1不是素数
    }
    else if(num == 2)
    {
        printf("Y");                 //2是素数
    }
    else
    {
    for(i = 2;i < num;i++)
    {
        if(num%i == 0)
        {
            printf("N");             //不是素数
            break;
        }
        else
        {
            count++;
        }
    }
    if(count == (num - 2))
        printf("Y");                 //是素数
    }
    return 0;
}
