#include <stdio.h>
#include <math.h>

double num_h ,num_d ,num_n;
int num;

int main()
{
    for( num_h = 1.0; num_h < 10.0; ++num_h)
    {
        for( num_d = 0.0; num_d < 10.0; ++num_d)
        {
            for( num_n = 0.0; num_n < 10.0; ++num_n)
            {
                num = (int)pow(num_h , 3.0 ) + (int)pow(num_d , 3.0 ) + (int)pow(num_n , 3.0 );
                if ( num == num_h*100 + num_d*10 + num_n ) 
                {
                    printf("%d\n" ,num);
                }
                
            }
            
        }
        
    }
    return 0 ;
}