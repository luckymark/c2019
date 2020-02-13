#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function_2.h"

int main()
{
	char mingwen[200]={0},key[200]={0},miwen[200]={0};
	char ch;
	int i;
	
	printf("Please input the key\n");
	input(key);
	printf("Please input what you want to derypt£º\n");
	input(miwen);
	
	decrypt(key,miwen,mingwen);
	printf("mingwen:\n");
	output(mingwen);
	
	return 0; 
	
 } 
