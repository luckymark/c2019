#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define SCREENLENGTH 10
#define SLEEPTIME 300  //if you can't see the letter move,please modify this number.
void PrintSpace(int n) //enter the amount of space.
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}
int main()
{
    while (1)
    {
        int j = 0;
        int TempForDection = 0;
        while (j >= 0 && j <= SCREENLENGTH) //Condition is very clear.
        {

            PrintSpace(j);
            printf("S");
            if (TempForDection == 0)
            {
                j++;
            }
            if (TempForDection == 1)
            {
                j--;
            }
            if (j == SCREENLENGTH)
            {
                TempForDection = 1;
            }
            if (j == 0)
            {
                TempForDection = 0;
            }
            Sleep(SLEEPTIME);
            system("cls");
        }
    }
    return 0;
}