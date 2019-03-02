#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    int i;
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }

    return 1;
}

int main() {
    const int UP = 2000;
    int i;
    clock_t start, end;
    double totalTime;

    start = clock();

    printf("%d\t", 2);
    for (i = 3; i < UP; i += 2) {
        if (isPrime(i)) printf("%d\t", i);
    }

    end = clock();
    totalTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntotal time: %fms \n", totalTime);

    system("pause");
    return 0;
}
