#include <stdio.h>
#include <stdlib.h>

#define N 12

long count = 0;

void move(int i, int j) {
    ++count;
    printf("%d -> %d\n", i + 1, j + 1);
}

int left(int i, int j) {
    int k;
    for(k = 0; k < 3; k++) {
        if(k != i && k != j) return k;
    }
    return -1;
}

void hanio(int n, int i, int j) {
    if(n == 1) {
        move(i, j);
        return;
    }

    int lf = left(i , j);
    hanio(n - 1, i, lf);
    move(i, j);
    hanio(n -1, lf, j);
   
}

int main() {
    hanio(N, 0, 1);
    printf("total steps: %d\n", count);

    system("pause");
    return 0;
}
