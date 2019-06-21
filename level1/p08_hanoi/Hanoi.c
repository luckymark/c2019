#include<stdio.h>
int count=0;
int hanoi(int n,char A,char B,char C)
{
	 if(n==1){
	 	printf("%c-->%c\n",A,B);
	    count++;
		return;
	 }
	 hanoi(n-1,A,C,B);
	 printf("%c-->%c\n",A,B);count++;
	 hanoi(n-1,C,B,A);
	 return count;
}
int main()
{
	int n;
	scanf("%d",&n);
	int count;
	count=hanoi(n,'A','B','C');
	printf("%d",count);
    return 0;
}
