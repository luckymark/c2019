#include "a.h"
int main(void) 
{	int a; 
	printf("请输入一个数字 1代表加密 0代表解密");
	scanf("%d",&a);
	if(a==1)
	{
		encrypt();
	}
	else if(a==0)	
	{
		decrypt();
	}
	else	
	{
		printf("错误输入");
	}
	return 0;
}


