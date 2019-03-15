#include<stdio.h>
int main(){
	float y = 9.000;
	while (y+=1){
		float t = y * (1.000 / 6.000 + 1.000 / 12.000 + 1.000 / 7.000) + 9;
		if (t * 2== y){
			printf_s("丢番图当时的年龄是：%d", int(y));
			break;
		}
	}
	return 0;
}