#include <stdio.h>
#include <windows.h>
#define N 78
unsigned int sleep(unsigned int seconds);
int main()
{
    int i,j;
    while(1)
    {
        for(i=0;i<N;i++)
        {
            for(j = 0;j <= i;j++)
            {
                printf(" ");
            }
            printf("s");
            Sleep(50);
            system("cls");
        }
        for(i=N;i>0;i--)
        {
            for(j = 0;j <= i;j++)
            {
                printf(" ");
            }
            printf("s");
            Sleep(100);
            system("cls");
        }
    }
    return 0;
}
