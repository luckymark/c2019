#include <stdio.h>
void getThreeDigitNumber(const int targetnumber,int *digit_number)
{
    int i=targetnumber;
    int j=0;
    while(i)
    {
        digit_number[j++]=i%10;
        i/=10;
    }
}
int main()
{
    int digit_number[3];
    for(int i=100;i<1000;i++)
    {
        int sum=0;
        get_threeDigit_Number(i,digit_number);
        for(int j=0;j<3;j++)
        {
            sum+=digit_number[j]*digit_number[j]*digit_number[j];
        }
        if(sum==i){
            printf("%d ",i);
        }
    }
    return 0;
}