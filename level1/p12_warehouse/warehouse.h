#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define TYPE 5
#define MAX 5
struct part{
		char type [TYPE];
		int quantity;
	};
extern struct part depository[MAX];
void output();
void insert();
void out();
void Read();
void Write();
extern struct part depository[MAX];
