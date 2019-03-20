#include <stdio.h>
#include <stdlib.h>


int is_prime(int n);
int main()
{
    int i;
    for(i=2; i < 1000; i ++)
    {
        if(is_prime(i))
        {
            printf("%5d ",i);
        }
    }
    return 0;
}


int is_prime(int n){
    int i;
    for(i=2;i<n;i++){
        if(n%i==0) return 0;}

    return 1;

}
