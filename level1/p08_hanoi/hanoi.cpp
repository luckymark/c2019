#include <stdio.h>
#include <string.h>
/*
 思路：1.把 n-1个盘子先移动到2号底座
       2.把1号底座上剩下的一个盘子移动到3号底座上
       3.再把n-1个盘子从2号底座移动到3号底座上
*/
void move(char origin, char aim);
void hanoi(int n,char origin ,char aim,char mid);
int main()
{
	 int n;
	printf("input your number");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}
 void hanoi(int n,char origin ,char mid,char aim)
 {
   if(n==1)
  	return;
  	hanoi(n-1,origin ,aim,mid);
  	move(origin,aim);
  	hanoi(n-1,mid,origin,aim);
 	}
void move(char origin, char aim)
{
	printf("%c ---> %c\n", origin, aim);
}


