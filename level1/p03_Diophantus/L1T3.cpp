### 编程解决下面的问题：

取自《希腊诗选》（Greek Anthology）：

丢番图的童年经过了他一生的六分之一，

青年经过了十二分之一，

又有七分之一的时间是单身汉。

结婚五年后得了个儿子，

儿子比父亲先死四年，

年级是他的一半。

问儿子死时丢番图多大？
#include <stdio.h>
int main()
{	
    int age;
    for(age=1;;age++)
    {
        if(age*1.0/6+age*1.0/12+age*1.0/7+5+4==age*1.0/2)
        {	
	    age-=4; 
        printf("丢番图儿子死时丢番图%d岁。",age);
        break;
        }
    }
}
