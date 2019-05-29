#include<bits/stdc++.h>

#include <stdlib.h>
#include<time.h>   

using namespace std;

int prime(int x)
{   int s;
    s=sqrt(x) ;
    int i;
    for (i=2;i<=s;i++)
        if (x%i==0) return 0;
    return 1;
}

int main(){
	int i;
	printf("   2\n");
	for(i=3;i<=1000;i+=2)
	{
		if(prime(i)==1)
		{
			printf("%4d\n",i);
		}
	}
}

