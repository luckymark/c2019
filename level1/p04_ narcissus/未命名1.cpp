#include<stdio.h>

int main(){
	int n,i,j,k;
	for(n=100;n<1000;n++){
		i=n%10;
		j=n/10%10;
		k=n/100;
		if (n==i*i*i+j*j*j+k*k*k){
			printf("%d\n",n);
		}
	}
	return 0;
}

