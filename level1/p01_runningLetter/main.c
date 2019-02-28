#include <stdio.h>
#include <stdlib.h>
#define N 30
int main()
{
    int x=0;
    int C=1;
    while (1)
    {
        x=x+C;
        system("cls");
        for (int i=0;i<x;i++)
        {
            printf (" ");
        }
        printf("A");
        if(x==N)
        {
            C=-1;
        }
        if(x==0)
        {
            C=1;
        }




    }

}
