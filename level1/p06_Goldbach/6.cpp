#include<stdio.h>
#include<stdlib.h>

// 在100范围内验证哥德巴赫猜想的正确性 证100以内任一大于2的偶数都可写成两个质数之和   
int prime(int n)
{
	int d,result;
	for(d=2;d*d<=n;d++){
		if(n%d==0)
		break;	
	}
	if(d*d>n)//素数 
	result=0;
	else
	result=1;
	return(result);			
} 
int main()
{
	int i,j;
	for(i=4;i<=100;i=i+2){
		for(j=2;j<i;j++){
			if(prime(j)==0&&prime(i-j)==0)
			break;	
		}
		if(j<i)
		printf("%d %d %d\n",i,j,i-j);
		else
		printf("%d is wrong",i);
	}
	system("pause");	
	return 0;
}
