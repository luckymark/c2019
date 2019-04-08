#include "hanoi.h"

int main(int argc, char const *argv[])
{
    int n = 1;

    printf("How many disc do you have? \n");
    scanf("%d", &n);
    move(n, 'A', 'B', 'C');
    system("pause");
    return 0;
}
