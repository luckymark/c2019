#include <stdio.h>
#include <math.h>

int main()
{
    int  i,j,sqr,k ;
    int n = 2;
    int prm[25];
    int temp[200] = {0};
    int a,b,d;
    int c = 0;//100以内素数存入数组
    for(i=5;i<=100;i = i+2)
    {
        k = 0;
        sqr = sqrt(i);
        for(j =2;j<=sqr;j++)
        {
            if(i%j == 0)
            {
            k++;
            }
        }
        if(k == 0)
        {
            prm[n] = i;
            n++;
        }
    }
    prm[0] = 2;
    prm[1] = 3;
        for(a = 0;a<25;a++)//对数组进行标记
        {
            for(b = a;b<25;b++)
            {
            c = prm[a] +prm[b];
            temp[c] = 1;
            printf("%d~",c);
             }
        }
        printf("that is");//判断哥德巴赫猜想
    for(d = 4;d<=100;d = d + 2)
    {
        if(temp[d] == 0)
        {
            printf(" not ");
            break;
        }
    }
    return 0;
}
