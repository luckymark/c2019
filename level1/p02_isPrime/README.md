### 功能要求：

1. 任意输入一个正整数n
1. 判断n是否为素数
#include<cstdio>
#include<cstdlib>
#include <cmath>
using namespace std;
bool t;
void fx(int i)
{
    for(int j=0;j<=sqrt(i);++j)
    {
        if(i%j==0)
            t=0;
        else
            t=1;
    }
}
int main()
{
    int i;
    t=0;
    printf("input=");
    scanf("%d",&i);
    if(t==1)
        printf("yes");
    else
        printf("no");
    return 0;
}
