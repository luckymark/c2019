#include<stdio.h> 
#include<math.h>
#define N 100
int isprime(int a);
int main()
{
	int n,a,w;
	for(n=4;n<=N;n+=2)
	{
		w=0;
		for(a=2;a<100;a++)
		{
		  if(isprime(a)&&isprime(n-a))
		     w++;
	    }
	    if(w==0)
	       break;
	}
	if(n==102)
	  printf("It proves right.");
	else
	  printf("It proves wrong."); 
	return 0;
}
int isprime(int a)
{
	int i,s;
	s=sqrt(double(a));
	for(i=2;i<=s;i++)
	{
		if(a%i==0)
		  break;
	}
	return (i>s)? a:0;
}
