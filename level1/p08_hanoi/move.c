#include"hanoi.h"

void move(int n, char from, char via, char aim)
{
    if (n == 1) print(n, from, aim);
    else
    {
        move(n-1, from, aim, via);
        print(n, from, aim);
        move(n-1, via, from, aim);
    }
}