#include <stdio.h>
#include <stdlib.h>
int main(){
    int yournumber;
    int index;
    int n;
    printf("Please enter your number:");
    scanf("%d",&yournumber);
    printf("\n");
    if(yournumber==2)
        printf("Yournumber %d is a prime.",yournumber);
    else{
        for(index=0,n=1;n<yournumber;n++){
            if(yournumber%n==0)
                index++;
        }
        if(index==1)
            printf("Yournumber %d is a prime.",yournumber);
        else
            printf("Yournumber %d is not a prime.",yournumber);
    }



    return 0;
}
