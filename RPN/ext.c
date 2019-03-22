//提取数

#include<string.h>

#define N 200

extern int num[N/2];    //数字栈

int ext(char exp[])
{
        int len = strlen(exp);
        int ten = 1;
        int num = 0;

        for(int i = len - 1; i >= 0; --i)
        {
                num = num + (exp[i] - '0') * ten;
                ten = ten * 10;
        }

        return num;
}
