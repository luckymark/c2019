#include <stdio.h>
#include <math.h>
 
int isPrime(int n);
 
int main()
{
    int i = 0;
    int j = 0;
    int k1 = 0;
    int k2 = 0;
    int even[50];
    int ret1 = 0;
    int ret2 = 0;
    int count = 0;
    for(i=4;i<=100;i+=2) //�ֱ���ÿ����ż����
    {
        count = 0;
        j = i;
        k1 = j-1 ; 
        while(k1>=(j/2))
        {
            ret1 = isPrime(k1);
            if(ret1)//k1������
            {
                k2 = j - k1;//��ȡk2
                ret2 = isPrime(k2);//�ж�k2�Ƿ�������
                if(ret2)//k2������
                {
                    printf("%d = %d + %d,", j, k2, k1);
                    count ++;
                }
            }
            k1--;
        }
        printf("%d���Բ��Ϊ%d�飡\n", i, count);
 
    }
    return 0;
}
int isPrime(int n)
{
    int i = 0;
    int a =sqrt(n);
    if(n<=1)
    {
        return 0;
    }
    if(2==n)
    {
        return 1;
    }
    for(i=2;i<a;i=i+1)
    {
        if(0==n%i)
        {
            return 0;
        }
    }
    return 1;
}
