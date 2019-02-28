#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#define N 121
unsigned int sleep(unsigned int seconds);
int system(const char*string);

int main(){
    int i,a;
    i=1;
    while(i<N){
        system("cls");
        a=1;
        while(a<i){
            printf(" ");
            a++;
        }
        printf("R");
        Sleep(100);
        i++;
    }
    while(i>=N&&i<2*N){
        system("cls");
        a=1;
        while(a<(2*N-i-1)){
            printf(" ");
            a++;
        }
        printf("R");
        Sleep(100);
        i++;
    }
    system("pause");

    return 0;
}
