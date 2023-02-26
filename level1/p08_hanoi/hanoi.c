#include <stdio.h>
#include <math.h>
void hanoi(int,char,char,char);
int main()
{
    int n;
    printf("������Բ�̸�����");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    int count = pow(2,n) - 1;
    printf("һ����Ҫ%d����",count);
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
