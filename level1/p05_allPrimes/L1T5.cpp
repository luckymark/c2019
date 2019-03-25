#include<stdio.h>
#include <math.h>
#include <Windows.h>
void CreatePrime(int *primes, int n)
{
 	int i, j, s;
    primes[0] = primes[1] = 0;
    for(i = 2; i < n; i++)
    primes[i] = 1;
    s = sqrt(n);
    for(i = 2; i<= s; i++) 
	{
       if(primes[i]) 
	  {
        for(j = 2 * i; j < n; j+=i)
        primes[j] = 0; 
      }
    }    
}
int main() 
{
	int i;
	double run_time;
	LARGE_INTEGER time_start;	
	LARGE_INTEGER time_over;	
	double dqFreq;		
	LARGE_INTEGER f;	
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);	
    int IsPrime[1000];
    CreatePrime(IsPrime, 1000);
    for(i = 2; i < 1000; i++)
      if(IsPrime[i]) 
	  printf("%d\t",i);
	QueryPerformanceCounter(&time_over);	
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;
	printf("\nrun_time£º%fus\n",run_time);
	return 0;
}

