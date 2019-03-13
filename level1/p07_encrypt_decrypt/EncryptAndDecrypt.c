#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* des, char* src) {
    int n = strlen(src);
    for (int i = 0; i < n; i++) {
        des[i] = ((~src[i] & 127) + 43) % 95 + 32;
    }
    des[n] = '\0';
}

void decrypt(char* des, char* src) {
    int n = strlen(src);
    for (int i = 0; i < n; i++) {
        des[i] = ~(((((int)src[i] - 32 + 95) % 95) - 43 + 95) % 95) & 127;
    }
    des[n] = '\0';
}

int main() {
    const int N = 1024;
    char inputs[N];
    char ret[N];
    int i = 0;

    printf("Input a string:\n");
    while ((inputs[i++] = getchar()) != '\n');
    inputs[--i] = '\0';
    printf("your input is: %s\n", inputs);

    encrypt(ret, inputs);
    printf("after encrypt: %s\n", ret);

    decrypt(ret, ret);
    printf("after decrypt: %s\n", ret);

    system("pause");
    return 0;
}
