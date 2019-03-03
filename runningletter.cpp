#include <stdio.h>
#include <windows.h>
#define l 80
void black(int i){
	int j;
	for(;i!=abs(i-80);i--){
		for(j=0;j<=abs(i);j++){
			printf(" ");
		}
		printf("H");
		system("cls");
	}
	
}
int main(){
	int i, j;
	black(0);
	black(l);
	return 0;
} 

