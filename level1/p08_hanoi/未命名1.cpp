#include <stdio.h>
void mov(int n, char a, char b, char c) {
    if (n == 1) {
        printf("%c%c\n", a, c);
    } else {
        mov(n - 1, a, c, b);//��һ�εݹ飬��ʾ��ͷ��n��1���a����c�Ƶ�b
        printf("%c%c\n", a, c);//��ʾ�����һ�飬��a�Ƶ�c
        mov(n - 1, b, a, c);//�ڶ��εݹ飬��ʾ��ʣ��n��1���b����a�Ƶ�c
    }
}
int main() {
    int n;
    n=64; 
    mov(n, '1', '2', '3');
    return 0;
}

