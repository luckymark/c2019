#include <stdio.h>
#include <string.h>
/*
 ˼·��1.�� n-1���������ƶ���2�ŵ���
       2.��1�ŵ�����ʣ�µ�һ�������ƶ���3�ŵ�����
       3.�ٰ�n-1�����Ӵ�2�ŵ����ƶ���3�ŵ�����
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


