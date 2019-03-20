#include<stdio.h>
int main()
{
	int i, son;
	for(i=20; ; i++)
	{
		son=i/2;
		if(i%12==0 && i%7==0 && (i/6+i/12+i/7+9)==son)
		{
			printf("When his son died, Diophantus is %d years old.\n", i-4);
			break;
		}
	}
	
	return 0;
}
