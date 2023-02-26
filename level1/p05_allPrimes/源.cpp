#include<stdio.h>
int main(){
	int m[1000] = { 0, 2 };
	int i, n = 1;
	for (i = 2; i <= 1000; i++){
		for (int k = 1; k <= n; k++){
			if (i % m[k] == 0)break;
			else if (k == n){
				n++;
				m[n] = i;
				printf_s("%d ", i);
			}
		}
	}
	return 0;
}