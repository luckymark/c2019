#include <cstdio>
int main()
{
    int i=0;
    for(;i<100;i++)
    if((1*12*7/6*i+1*12*7/12*i+1*12*7/7*i+5*12*7+1*12*7/2*i+4*12*7)==i*12*7)
    break;
    printf("His age is :%d",i);
}