#include"hanoi.h"

int t = 0;
void print(int n, char from, char aim)
{
    printf("Step %d: move disc %d from %c to %c. \n", ++t, n, from, aim);
}