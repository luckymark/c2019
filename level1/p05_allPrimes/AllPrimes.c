#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    const int UP = 2000;
    clock_t start, end;
    double totalTime;

    start = clock();

    printf("%d\t", 2);
    for (int i = 3; i < UP; i += 2) {
        if (isPrime(i)) printf("%d\t", i);
    }

    end = clock();
    totalTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntotal time: %fms \n", totalTime);

    system("pause");
    return 0;
}
