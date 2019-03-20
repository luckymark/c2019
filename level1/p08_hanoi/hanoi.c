# include<stdio.h>

void hanoit (int n,char A,char B,char C);
void move (char FROM,char TO);

int main ()
{
	const int m = 64;
	char A = 'A';
	char B = 'B';
	char C = 'C'; // A B C 代表从左到右的三根柱子 

	hanoit(m,A,B,C);
	
	return 0;	
}

void hanoit (int n,char A,char B,char C)
{
	if(n == 1)
		move(A, C);
	else
	{
		  hanoit (n-1, A, C, B);
	    move (A, C);
	    hanoit (n-1,B, A, C);
	 } 

}

void move (char FROM,char TO)
{
	printf("move %c to %c\n",FROM, TO);
}
