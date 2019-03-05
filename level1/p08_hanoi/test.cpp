#include<stdio.h>

long long steps = 0;

long double hanoi(int n, char a, char b, char c) {
	if (n == 1){
		printf("%c-->%c\n", a, c);
		++steps;
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%c-->%c\n", a, c);
		++steps;
		hanoi(n - 1, b, a, c);
	}
	return steps;
}

int main() {
	int flats;
	printf("Enter hanoi flats:\t");
	scanf("%d", &flats);
	printf("The steps are: ( assume from A to C )\n");
	hanoi(flats, 'A', 'B', 'C');
	printf("\nNeed %ld steps totally.", steps);
}



