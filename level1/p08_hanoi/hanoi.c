#include <stdio.h>

void move(char x, char y);
void hanoi(int n,char one ,char two,char three)
{
	void move(char x,char y);
	if(n==1)
  		move(one, three);
	else
	{
 		hanoi(n-1,one,three,two);
		move(one,three);
		hanoi(n-1,two,one,three);
	}
}
void move(char x,char y)
{
	printf("%c-->%c\n",x,y);
}
 
void main()
{
	int n;
	printf("input your number");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}
