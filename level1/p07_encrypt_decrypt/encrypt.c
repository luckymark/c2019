#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main()
{
	char mingwen[200]={0},key[200]={0},miwen[200]={0};
	char ch;
	int i;
	
	printf("Please input the key:(purely use numbers)\n");
	input(key);
	printf("Please input what you want to enrypt£º\n");
	input(mingwen);
	
	encrypt(key,mingwen,miwen);
	printf("miwen:\n");
	output(miwen);
	
	return 0; 
	
 } 
