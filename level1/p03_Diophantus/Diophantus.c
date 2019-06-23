#include <stdio.h>

float age_son ,age_count;

int main()
{
    for( int age_DIO = 1.0; age_DIO < 200.0; ++age_DIO )
    {
        //printf("%d\n",(int)age_DIO);
        age_count = age_DIO;
        age_son = age_DIO / 2.0;
        age_count = age_count - age_DIO / 6.0 ;
        age_count = age_count - age_DIO / 12.0;
        age_count = age_count - age_DIO / 7.0;
        age_count = age_count - 5.0;
        if ( age_count == age_son + 4.0 ) 
        {
            printf("%d\n" ,(int)age_DIO);
            break;
        }
    }

    return 0;
}