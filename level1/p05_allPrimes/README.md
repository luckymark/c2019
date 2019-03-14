### 功能要求：

1. 打印2-1000以内的所有素数
1. 打印出总的计算时间
1. 尽可能优化算法的效率
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
int main()
{
    clock_t st,et;
    st=clock();
    int i=3,j=2;
    printf("2\n");
    for(i=3;i<=1000;++i)
    {
        for(j=2;j<=sqrt(i);++j)
        {
            if(i%j==0)
                break;
        }
        if(j>=sqrt(i))
            printf("%d\n",i);
    }
    et=clock();
    printf("time is %lu",et-st);
    return 0;
}
