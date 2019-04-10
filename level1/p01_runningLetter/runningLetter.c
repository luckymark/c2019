#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int getwidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    // rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return columns;
}
int main() {
    int space;
    while (1) {
        space = getwidth() - 1;
        for(int i = 0; i < space; i++) {
            for(int j = 0; j < i; j++) {
                printf(" ");
            }
            printf("X");
            system("cls");
        }
        for(int i = space; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                printf(" ");
            }
            printf("X");
            system("cls");
        }
    }
    return 0;
}
