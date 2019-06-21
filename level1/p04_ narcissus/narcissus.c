#include <stdio.h>
#include <math.h>
#define LOWERBOUND 100
#define UPPERBOUND 999

void initar(int ar[]);
int  sum_bits(int i, int ar[]);
int ipow(int i);


int main(void)
{
	int num[10];
	int i;
	initar(num);
	
	for (i= LOWERBOUND; i< UPPERBOUND+1; i++)
	{
		
		int sum=0;
		sum= sum_bits(i, num);
		if( i==sum )
			printf("%d is narcissus.\n", i);
	}
	
	return 0;
} 
//function 1
void initar(int ar[])
{
	int i;
	
	for (i= 0; i<10; i++)
		ar[i]= i*i*i;
	
}
//function 2
int  sum_bits(int i, int ar[])
{
	int sum= 0;
	int j, power, tmp;
	
	for (j=2; j>-1; j--)
	{
		power= ipow(j);
		tmp= i/power;
		i-= tmp*power;
		sum+= ar[tmp];
	}
	
	return sum;
}
//function 3
int ipow(int i)
{
	int j= 1;
	int cnt;
	for (cnt=0; cnt<i; cnt++)
	{
		j*= 10;
	}
	
	return j;
}

