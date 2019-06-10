#include <stdio.h>
#include <math.h>
void hanoi(int,char,char,char);
int main()
{
    int n;
    printf("请输入圆盘个数：");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    int count = pow(2,n) - 1;
    printf("一共需要%d步。",count);
    return 0;
}
void hanoi(int n,char a,char b,char c)
{
    if(n == 1)
        printf("%c-->%c\n",a,c);
    else
    {
        hanoi(n - 1,a,c,b);
        printf("%c-->%c\n",a,c);
        hanoi(n - 1,b,a,c);
    }
}
