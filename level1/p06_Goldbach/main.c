#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Test(int n)
{
    if(!(n&1))
        return 0;
    int i,b;
    {
        for(i=2;2*i-1<sqrt(n);i++)
        {
             b =0;
            if(n%(2*i-1)==0)
            {
                b++;
            }
        }
        if(!b)
            return 0;
        return 1;
    }
}
int main()
{
    int i,j,n,q,k;
    for(n=1;n<50;n++)
    {
    for(i=2;i<26;i++)
    {
        j=2*i-1;
        q=2*n-j;
        if(Test(q)&&Test(j))
            k++;

    }
    if(k)
        printf("%d is yes\n",n);
    else
        printf("%d is no\n",n);
    }
    return 0;
}
