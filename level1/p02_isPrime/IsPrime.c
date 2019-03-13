#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {

    if(n == 1) return false;
    if(n == 2) return true;

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }

    return true;
}

int main() {
    int n;

    //get n from input
    printf("Input a integer:\n");
    scanf("%d", &n);

    if(isPrime(n)) {
        printf("%d is a prime\n", n);
    }else{
        printf("%d is not a prime\n", n);
    }

    system("pause");
    return 0;
}

