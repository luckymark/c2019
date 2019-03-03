#include <stdio.h> 
int main(){
	int i, t;
	for(i=1;i<75;i++){
		if(2*i%6==0 && 2*i%12==0 && 2*i%7==0){
			if(i==2*i/6+2*i/12+2*i/7+9){
				printf("¶ù×ÓËÀÊ±¶ª·¬Í¼%dËê",2*i-4);
			}
		}
	}
	return 0;
	 
}
