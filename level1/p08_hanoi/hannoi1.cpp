#include <stdio.h>
#define N 64 
void exchange(int n, char a, char b, char c) ;
int main(){
	exchange(N, 'a', 'b','c');
	
}
void exchange(int n, char a, char b, char c){
	if(n==1){
		printf("%c->%c\n", a, c);
		//return;
	}
	else{
		exchange(n-1, a, c, b);
		printf("%c->%c\n",a, c);
		exchange(n-1,b, a, c);
		
	}
}
