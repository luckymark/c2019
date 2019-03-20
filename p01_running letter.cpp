#include<stdio.h>
#include<stdlib.h>
#define length 80
int main() {
	while (1) {
		for (int i = 1; i <= length; i++) {
			for (int j = 1; j <=i; j++)
				printf(" ");
			printf("R");
			system("cls");
		}
		for (int i = 1; i <= 80; i++) {
			for (int j = 1; i + j <= length; j++)
				printf(" ");
			printf("R");
			system("cls");
		}
	
	}
	return 0;
}

