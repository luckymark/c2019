#include <stdio.h>
#define range 100
int isPrime(int num); 
int main(){
	int i, j, k, goldbach;
	goldbach=0;
	for(i=4;i<=range;i+=2){
		for(j=2;j<=i/2;j++){
			k=i-j;
			if(isPrime(k) && isPrime(j)){
				goldbach++;
				break;
			}
		}
	}
	if(goldbach==range/2-1)
		printf("%d以内成立",range); 
	else
		printf("%d以内不成立",range);
	return 0;
}
int isPrime(int num){
	int i, t;
	t=0;
	for(i=2;i<num;i++){
		if(num%i==0){
			t++;
		}	
	}
	if(t==0)
		return 1;
	else
		return 0;
}
