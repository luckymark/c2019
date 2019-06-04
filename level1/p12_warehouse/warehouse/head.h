#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable : 4996)
#ifndef _HEAD_H
#define _HEAD_H
typedef struct Node{
	char model[5];
	int data;
	Node* next;
}*list, linkedlist;
#endif
