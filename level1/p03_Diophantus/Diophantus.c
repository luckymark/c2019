#include <stdio.h>

int main(){
    int year = 0;
    double temp;
    while(1){
        year++;
        temp = year*75.0/84.0+ 9.0;
        if(temp==year){
            break;
        }
    }
    printf("%d",year);
    return 0;
}