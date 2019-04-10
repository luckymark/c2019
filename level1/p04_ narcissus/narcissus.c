#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c, i;
    for (i = 100; i < 1000; i++) {
        c = i%10;
        b = (i%100 - i%10)/10;
        a = (i - i%100)/100;
        if (pow(a,3) + pow(b,3) + pow(c,3) == i)
            printf("%d is a narcissus.\n", i);
    }
    return 0;
}