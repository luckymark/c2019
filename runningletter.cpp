#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int LENGTH = 30;
	char al;
	scanf("%c",&al);
	int i,num,j=0;
	for(i=0;i<LENGTH;i++){
		system("cls");
		num=j;
		while(num){
			printf(" ");
			num--;
		}
		printf("%c",al);
		j++;
	}
	for(i=0;i<LENGTH;i++){
		system("cls");
		num=j;
		while(num){
			printf(" ");
			num--;
		}
		printf("%c",al);
		j--;
	}
	return 0;
 } 
