#include<stdio.h>
int main(){
	float y = 9.000;
	while (y+=1){
		float t = y * (1.000 / 6.000 + 1.000 / 12.000 + 1.000 / 7.000) + 9;
		if (t * 2== y){
			printf_s("����ͼ��ʱ�������ǣ�%d", int(y));
			break;
		}
	}
	return 0;
}