#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100

int main() {
    int i, j;
    bool flag = false;
    char pads[WIDTH] = "";

    while (1) {
        flag = !flag;
        for (i = 0; i < WIDTH - 1; i++) {
            if (flag) {
                strcat(pads, " ");
            } else {
                pads[strlen(pads) - 1] = '\0';
            }
            printf("%s", pads);
            putchar('A');
            system("CLS");
        }
    }

    return 0;
}
