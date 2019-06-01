### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动

#include<cstdio>
#include<cstdlib>
using namespace std;
#define width 12
int main()
{
    int i=1,j;
    bool t=0;
    while(i<=width)
    {
        for(j=0;j<=i;++j)
        {
            printf(" ");
        }
        printf("r");
        system("cls");
        if(i==width) t=1;
        if(i==0) t=0;
        if(t==1) --i;
        else ++i;
    }
    return 0;
}



