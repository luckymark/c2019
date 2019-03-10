#include<cstdio>

using namespace std;

// by huang chong yi   2018081306006
bool Is_prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	if ( Is_prime(n) ) printf("%d is a prime !\n",n);
	else printf("%d is not a prime !\n",n);
	return 0;
} 
