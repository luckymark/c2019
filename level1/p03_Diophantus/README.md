### 编程解决下面的问题：

取自《希腊诗选》（Greek Anthology）：

丢番图的童年经过了他一生的六分之一，

青年经过了十二分之一，

又有七分之一的时间是单身汉。

结婚五年后得了个儿子，

儿子比父亲先死四年，

年级是他的一半。


#include <cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    float i;
    for(i=10;i<=150;i++)
    {
        if(i/6+i/12+i/7+i/2+9==i)
            printf("%f",i);
    }
    return 0;
}
