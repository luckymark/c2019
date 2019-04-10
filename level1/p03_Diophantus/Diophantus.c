#include<stdio.h>
#define MAX 125
int main(){
	float a;
	int year;
	 
    for(a=12.0;a<MAX;a++){
    	if((a-4)-(a/6+a/12+a/7+5)==a/2){
	        year=a-4;
		    printf("¶ù×ÓËÀÊ±¶ª·¬Í¼ %dËê\n",year);
	    }
    }
	
	return 0;
} 
