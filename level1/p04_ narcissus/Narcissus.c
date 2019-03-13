#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c;
    for (int i = 100; i < 999; i++) {
        a = i / 100;
        b = (i - a * 100) / 10;
        c = i % 10;

        if (a * a * a + b * b * b + c * c * c == i) printf("%d\t", i);
    }

    printf("\n");
    system("pause");
    return 0;
}