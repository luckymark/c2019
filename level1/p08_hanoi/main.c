#include <stdio.h>
#include <stdlib.h>
void Move(char a,char b)
{
    printf("%c->%c  ",a,b);
}
void hannota(int n,char a,char b,char c)
{
    if(n==1)
        Move(a,c);

    else {
        hannota(n-1,a,c,b);
        Move(a,c);
        hannota(n-1,b,a,c);
        }
}
int main()
{
    hannota(4,'A','B','C');
    return 0;
}
