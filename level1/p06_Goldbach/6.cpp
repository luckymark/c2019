#include<stdio.h>
#include<stdlib.h>

// ��100��Χ����֤��°ͺղ������ȷ�� ֤100������һ����2��ż������д����������֮��   
int prime(int n)
{
	int d,result;
	for(d=2;d*d<=n;d++){
		if(n%d==0)
		break;	
	}
	if(d*d>n)//���� 
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
