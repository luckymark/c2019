#pragma once
#include "material.h"
#include "hlibrary.h"
#define MAXQSIZE 1000
typedef struct
{
	brick *base;
	int head;
	int tail;
	
}Queue;

//initialize a queue to help construct the maze
void InitQueue(Queue* Q)
{
	Q->base=(brick*)malloc(MAXQSIZE * sizeof(brick));
	if (NULL==(Q->base))
		return;
	Q->head=Q->tail=0;
}
//enqueue operation
void enqueue(Queue*Q, brick en)
{
	if (Q->head==(Q->head+1) % MAXQSIZE)
		return;
	
	Q->base[Q->tail]=en;
	Q->tail=(Q->tail+1)%MAXQSIZE;
	
	
}
//get the length of the queue
int getLength(Queue Q)
{
	return (Q.tail-Q.head+MAXQSIZE) % MAXQSIZE;
	
}
//dequeue operation
void dequeue(Queue*Q, brick* B)//B stage the brick that is dequeued
{
	if (Q->head==Q->tail)
		return;
	
	srand((unsigned)time(NULL));
	int tmp=rand()%getLength(*Q);
	
	*B=Q->base[tmp];
	Q->base[tmp]=Q->base[Q->tail-1];
	Q->base[Q->tail-1]=*B;
	
	Q->tail=(Q->tail+MAXQSIZE-1)%MAXQSIZE;
	
	
}
//judge whether the Queue is empty
bool QisEmpty(Queue Q)
{
	if (Q.head==Q.tail)
		return true;
	else
		return false;
		
}
