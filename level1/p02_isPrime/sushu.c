#include <stdio.h>
int main()
{
    int num,i,count = 0;
    printf("input a number:");
    scanf("%d",&num);
    if(num <= 0)
    {
        printf("error!input again:");//��������һ��������
        scanf("%d",&num);
    }
    else if(num == 1)
    {
        printf("N");                 //1��������
    }
    else if(num == 2)
    {
        printf("Y");                 //2������
    }
    else
    {
    for(i = 2;i < num;i++)
    {
        if(num%i == 0)
        {
            printf("N");             //��������
            break;
        }
        else
        {
            count++;
        }
    }
    if(count == (num - 2))
        printf("Y");                 //������
    }
    return 0;
}
