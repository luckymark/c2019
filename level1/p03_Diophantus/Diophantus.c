#include<stdio.h>
int main()
{
	for(int age=12;age<=200;++age)//不能再多了
	{
		if(age%12==0&&age%7==0)
		{
			int x=age/6+age/12+age/7+5+age/2+4;
			if(x==age)
			printf("%d",x-4);
		}
	}
	
	return 0;
}
