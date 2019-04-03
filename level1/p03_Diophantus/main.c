#include <stdio.h>

int main()
{
    float age = 12, child,youth,solo,son,temp_f,temp_b = 200;
    while(1)
    {
        child = age/6;
        youth = age/12;
        solo = age/7;
        son =  age/2;
        if(age - son - child - youth - solo -5>4)
        {
                temp_b = age;
                age = (age+temp_f)/2;
        }
        else if(age - son - child - youth -solo -5<4)
        {
            temp_f = age;
            age = (age+temp_b)/2;
        }
        else
        {
            printf("he is %d",(int)age-4);
            break;
        }

    }
    return 0;
}
