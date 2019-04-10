#include<stdio.h>
int main(){
	int a;
	
	for(a=100;a<1000;a++){
		int g,s,b;
		g=a%10;
		s=a/10%10;
		b=a/100;
		if(g*g*g+s*s*s+b*b*b==a)
			printf("%d\n",a);
	}
	
	return 0;
}
