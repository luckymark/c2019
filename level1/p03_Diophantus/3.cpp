#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i ;
	for (i = 12; i <= 150; i++) {
		if (i % 12 == 0 && i % 7==0) {
			if (i == 75 * i / 84 + 9)
				break;
		}
	}
	printf("%d",i);
	system("pause");
	return 0;
}