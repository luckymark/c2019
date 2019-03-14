#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Test(int x)
{
    int i;
    if(x==1)
    {
        printf("no");
    }
    if(x==2)
        printf("yes");
    for(i=2;i<sqrt(x)+1;i++)
    {
        if(x%i==0)
        {
            printf("no");
            exit(1);
        }
    }
    printf("yes");
}

int main()
{
    int x;
    scanf("%d",&x);
    Test(x);
    return 0;
}
