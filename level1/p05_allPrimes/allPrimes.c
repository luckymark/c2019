#include <stdio.h>
#include <math.h>
#include <windows.h>
int main() {
    int start, stop, i, j; 
    start = GetTickCount();
    int prime[200];
    prime[0] = 2;
    int num = 0;
    for(i = 3; i <= 1000; i++) {
        for(j = 0; i%prime[j] != 0 && j <= num; j++) {
            if(prime[j] > sqrt(i)) {
                prime[num + 1] = i;
                num++;
                break;
            }
        }
    }
    for(i = 0; i <= num; i++)
        printf("%d ",prime[i]);
    stop = GetTickCount();
    printf("\ntime: %ld ms\n", stop - start);
    return 0;
}
