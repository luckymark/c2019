#include "a.h"
int main(void) 
{	int a; 
	printf("������һ������ 1������� 0�������");
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
		printf("��������");
	}
	return 0;
}


