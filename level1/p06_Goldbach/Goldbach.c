#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

int search(int* a, int i, int j, int t) {
    int m;
    while (i <= j) {
        m = (i + j) / 2;
        if (a[m] == t) {
            return m;
        } else if (a[m] < t) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    return -1;
}

int* twoSum(int* a, int n, int t) {
    int i, j, k;
    static int ret[2];
    for (i = 0; i < n; i++) {
        if ((k = search(a, i, n - 1, t - a[i])) > -1) {
            ret[0] = i;
            ret[1] = k;
            return ret;
        }
    }
    return NULL;
}

int main() {
    const int UP = 100;

    int a[UP / 2];
    int* tmp = NULL;
    int i = 0;

    a[i++] = 2;
    for (int j = 3; j <= 100; j += 2) {
        if (isPrime(j)) a[i++] = j;
    }

    for (int j = 4; j <= 100; j += 2) {
        if (tmp = twoSum(a, i, j)) {
            printf("%d = %d + %d\n", j, a[tmp[0]], a[tmp[1]]);
        } else {
            printf("%d cannot be the sum of two primes!", j);
            system("pause");
            return 0;
        }
    }
    printf(
        "All evens not larger than 100 (except 2) can be the sum of two "
        "primes!\n");

    printf("\n");
    system("pause");
    return 0;
}