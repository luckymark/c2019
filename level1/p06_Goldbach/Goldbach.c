#include<stdio.h>
#include<math.h>
#define MAX 100

int isprime(int n);

int main()
{
	for(int i=2,num=4;num<MAX;++i,num=2*i)
	{
		for(int d=0;d<num/2;++d)
		{
			int flag_1=isprime(num/2-d);
			int flag_2=isprime(num/2+d);
			if(flag_1&&flag_2)
			{
				printf("ż��%d�ɱ���ʾΪ����%d��%d�ĺ�\n",num,num/2-d,num/2+d); 
				break;
			}
		}
	}
	
	return 0;
}

int isprime(int n)
{
	int flag=1;
	
	if(n%6!=1&&n%6!=5&&n>6)//���n����6�Ҳ���6�ı���Ϊ�� ,n�������� 
	flag=0;
	else 
	{
		for(int a=sqrt(n);a>=2;--a)
		{
			if(n%a==0)
			{
				flag=0;
				break;
			}
		}
	}
	
	return flag;
}
