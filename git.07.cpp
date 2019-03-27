#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
    char a[1000];
    printf("input =");
    gets(a);
    for(int i=0;i<1000;++i)
    {
        if(a[i]==0)
            break;
        else
            a[i]+=3;
    }
    puts(a);
    for(int i=0;i<1000;++i)
    {
        if(a[i]==0)
            break;
        else
            a[i]-=3;
    }
    puts(a);
    return 0;
}
