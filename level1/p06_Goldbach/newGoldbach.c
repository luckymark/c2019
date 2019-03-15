#include <stdio.h>
//在100范围内验证哥德巴赫猜想的正确性
//int isprime(int);
int main()
{
    int i,j,x,k;
    int num ;
    int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(i = 4;i < 100;i += 2)
    {

        for(j = 0;j < 25;j++)
        {
            num = 0;
            x = i - primes[j];
            for(k = 0;k<25;k++)
            {
                if(x==primes[k])
                    num = 1;
            }
            //num = isprime(x);
            if(!(x<2||num == 0||primes[j]>x))
                printf("%-3d= %-3d+ %-3d\n",i,primes[j],x);
        }
    }
    return 0;
}
/*int isprime(int num)
{
    int i;
    int primes[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(i = 0;i< 25;i++)
    {
       if(num = primes[i])
            return 1;
    }
    return 0;

}
*/
