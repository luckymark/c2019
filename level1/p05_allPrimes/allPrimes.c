#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tags[ 10000 ];
int num;

int main()
{
    clock_t start, finish;
    start = clock();
    for(int i = 0; i < 10000; i++)
    {
        tags[ i ] = 1;//预设良民证
    }
    
    for(int num = 2; num <= 100; num++)//素因数检查仅到100即可
    {
        if (!tags[ num ])//检查良民证
        {
            ++num;
        }
        else
        {
            for(int j = 2; j < 5000; j++) //拿走符合条件的num的倍数的良民证
            {
                if (num*j <= 10000) 
                {
                    tags[ num*j ] = 0;
                }
                else
                {
                    break;
                }
                
            }
            
        }
        
        
    }
    for(int l = 2; l < 10000; l++)//输出有良民证的数字
    {
        if (tags[ l ]) 
        {
            printf("%d\n" ,l);
        }
        
    }
    finish = clock();
    double total_time = (double) (finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds/n",total_time);

    return 0;
    
}