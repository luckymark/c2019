#include<stdio.h>
#include<stdlib.h>
//к╝оийЩ 
int main()
{
	int i,a,b,c;
	for(i=100;i<1000;i++){
		a=i%10;
		b=(i%100)/10;
		c=i/100;
		if(i==a*a*a+b*b*b+c*c*c)
		printf("%d,",i);
	} 
	system("pause");
	return 0;
}