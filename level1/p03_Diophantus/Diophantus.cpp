#include<stdio.h>
int main(void)
{
	int age;
	int a1,a2,a3,a4;
	int a5=(4+5);//³£ÊıÏî 
	a1=6,a2=12,a3=7,a4=2;
	printf("the equation is x/%d + x/%d + x/%d + 5 + 4 = x/%d\n",a1,a2,a3,a4);
	int tol=a1*a2*a3*a4;
	a1=tol/a1;
	a2=tol/a2;
	a3=tol/a3;
	a4=tol/a4;
	a5=tol*a5;
	age=a5/(a4-a1-a2-a3);
	printf("the diophantus's age is %d",age);
}
