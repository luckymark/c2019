#include<stdio.h> 

int main()
{
	float x;
	for(x=9.0;x<=120.0;x++)
	{
		if(x/6.0+x/12.0+x/7.0+5.0+x/2.0+4.0 == x)
		{
			printf("儿子死时丢番图年龄为：%d",int(x-4));
            		break;
		}
	}
	return 0;
}
