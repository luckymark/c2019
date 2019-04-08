#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float age = (5 + 4.0) / (1 - 1.0/6 - 1.0/12 - 1.0/7 - 1.0/2);
    int ans = age - 4;

    printf("%d \n", ans);
    system("pause");

    return 0;
}
