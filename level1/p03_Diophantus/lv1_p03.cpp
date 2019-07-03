#include<stdio.h>
int main()
{
	for(int age=1;;age++)
	{
		if(age/6+age/12+age/7+5+age/2+4==age)
		{
			printf("%d",age-4);
			break;
		}
	}
}
