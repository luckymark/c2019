#include <stdio.h> 
#include <time.h>
int main(){
	int i, j, t;
	clock_t ts, te;
	ts=clock();
	for(i=2;i<=1000;i++){
		t=0;
		for(j=2;j<i;j++){
			if(i%j==0){
				t++;
			}
		}
		if(t==0){
			printf("%d \n",i);
		}
	}
	te=clock();
	printf("\n运行时间%d毫秒",te-ts);
	return 0;
}
