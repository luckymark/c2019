#include<stdio.h>

void move(int n,char A,char B,char C)
{
	if(n==1){
		printf("move %d from %c to %c\n",n,A,C);
	}else{
		move(n-1,A,C,B);
		printf("move %d from %c to %c\n",n,A,C);
		move(n-1,B,A,C);
	}
}
void hanoi(int n,char A,char B,char C)
{
	if(n<=0){
		return ;
	}
	move(n,A,B,C);
}
int main()
{
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return n;
}
