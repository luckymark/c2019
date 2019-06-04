#include <stdio.h>
void mov(int n, char a, char b, char c) {
    if (n == 1) {
        printf("%c%c\n", a, c);
    } else {
        mov(n - 1, a, c, b);//第一次递归，表示把头上n－1块从a经过c移到b
        printf("%c%c\n", a, c);//表示把最后一块，从a移到c
        mov(n - 1, b, a, c);//第二次递归，表示把剩下n－1块从b经过a移到c
    }
}
int main() {
    int n;
    n=64; 
    mov(n, '1', '2', '3');
    return 0;
}

