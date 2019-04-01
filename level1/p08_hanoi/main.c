#include <stdio.h>

void move (int n,char from,char to)
{
    printf("把第%d盘子从%c移到%c\n",n,from,to);
}

void hanoi(int n,char from,char by,char to)
{
    if(n == 1)move(1,from,to);
    else
    {
    hanoi(n - 1,from,to,by);
    move (n,from,to);
    hanoi(n-1,by,from,to);
    }
}


int main()
{
    int n;
    printf("输入一共多少盘子:");
    scanf("%d",&n);
    char from,by,to;
    from = 'A';
    by = 'B';
    to = 'C';
    hanoi(n,from,by,to);
    return 0;
}
