#include <stdio.h>
#include <stdlib.h>

unsigned long count = 0;

void move(int i, int j) {
    ++count;
    printf("%d -> %d\n", i + 1, j + 1);
}

int left(int i, int j) {
    for(int k = 0; k < 3; k++) {
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
    int n;
    printf("input the total count of disks: ");
    scanf("%d", &n);
    hanio(n, 0, 1);
    printf("total steps: %d\n", count);

    system("pause");
    return 0;
}
