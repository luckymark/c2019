#include"basic.h"
#include<stdio.h>
#pragma warning(disable : 4996)//在VS里fopen没法直接使用，必须关掉警告

void print(char(*map)[15]);

void loadmap(int number, char(*map)[15]);