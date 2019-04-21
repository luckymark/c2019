#include"hanoi.h"
void move(char from,char to);
extern long long count;
void hanoi(int n,char from,char help,char to)
{
	if(n==0) return;
	count++;
	hanoi(n-1,from,to,help);
	move(from,to);
	hanoi(n-1,help,from,to);
}
void move(char from,char to)
{
	printf("%c-->%c\n",from,to);
}

