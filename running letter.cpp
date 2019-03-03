#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int i,j,a,b;
	for(i=0;i<=80;i++){
	  	for(j=0;j<i;j++){
	  		printf(" ");
    	}
		printf("%c ",'R');
    	system("cls");
	}
	for(a=80;a>=0;a--){
		for(b=0;b<=a;b++){
			printf(" ");
		}
		printf("%c ",'R');
    	system("cls");
	}
	return 0;
}
