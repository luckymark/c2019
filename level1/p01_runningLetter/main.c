#include <stdio.h>
#include <time.h>
#include<windows.h>

#define WALl_LENGTH 80
#define Speed 10

int main ()
{
    int i=1;
    while(1)
    {
        if(i<WALl_LENGTH)
        {
            for(int n=1;n<=i;n++)
            printf(" ");
        }
        else
        {
            for (int n=1;n<=2*WALl_LENGTH-i;n++)
            printf(" ");
        }
        Sleep(Speed);
        printf("@");
        system("cls");
        i++;
    }
    return 0;
}
