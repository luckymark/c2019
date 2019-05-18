### 功能要求：

1. 打印出所有3位水仙花数

水仙花数：n位数的每个数位的n次方之和等于该n位数本身

例如：153=1^3+5^3+3^3
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,i=100;
    while(i<1000)
    {
        c=i%10;
        b=i/10%10;
        a=i/100;
        if(pow(a,3)+pow(b,3)+pow(c,3)==i)
            printf("%d\n",i);
        ++i;
    }
    return 0;
}
