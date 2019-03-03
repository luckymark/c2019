#include <stdio.h>
#include <windows.h>
#include <math.h>
#define len 80
void blank(int i, int t){
	int j;
	for(;abs(i)!=t;i--){
		for(j=0;j<=abs(i);j++){
			printf(" ");
		}
		printf("H");
		system("cls");
	}
}
int main(){
	blank(0, len);
	blank(len, 0);
	return 0;
} 

