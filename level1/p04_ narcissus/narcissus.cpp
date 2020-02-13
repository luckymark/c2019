#include <stdio.h>
int main(){
	int i, j, k, a, b;
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			for(k=1;k<=9;k++){
				a=k*100+j*10+i;
				b=k*k*k+i*i*i+j*j*j;
				if(a==b){
					printf("%d ",a);
				}
			}
		}
	}
	return 0;
}
