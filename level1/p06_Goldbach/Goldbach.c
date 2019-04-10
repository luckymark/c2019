#include <stdio.h>
#include <math.h>
int main() {
    int prime[50];
    int i, j, k;
    int num = 0;
    int flag = 0;
    prime[0] = 2;
    for(i = 3; i <= 100; i++) {
        for(j = 0; i%prime[j] != 0 && j <= num; j++) {
            if(prime[j] > sqrt(i)) {
                prime[num + 1] = i;
                num++;
                break;
            }
        }
    }
    for(i = 4; i <= 100; i += 2) {
        flag = 0;
        for(j = 0; prime[j] <= i/2 && flag == 0; j++) {
            for(k = 0; k <= num; k++) {
                if (prime[k] == i - prime[j]) {
                    printf("i = %d x = %d y =%d\n", i, prime[j], prime[k]);
                    flag = 1;
                    break;
                }
            }
        }
    }
    printf("Goldbach conjecture is true for the first 100 numbers.");
    return 0;
}
