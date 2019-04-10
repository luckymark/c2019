#include <stdio.h>
#include <math.h>
int main() {
    int x, i;
    while (1) {
        printf("Please input a number: ");
        scanf("%d", &x);
        while (1) {    
            if(x <= 0 || x % 1 != 0) {
                printf("Please input a positive integer: ");
                scanf("%d", &x);
            }
            else 
                break;
        }    
        if(x == 1)
            printf("%d is not a prime.\n", x);
        else if(x == 2)
            printf("%d is not a prime.\n", x);
        else {    
            for(i = 2; x % i != 0; i++) {
                if (i > sqrt(x)) {
                    printf("%d is a prime.\n", x);
                    break;
                }
            }
        if (i <= sqrt(x))
            printf("%d is not a prime.\n", x);
        }
    }    
    return 0;        
}