#include<stdio.h>
int main()
{
	int i,j,dezi;
	for(i=1;i<=200;i++)
	{//age of father
		if(i%6==0&&i%12==0&&i%7==0)
		{
			dezi=i/6+i/12+i/7+5;
			for(j=1;j<=100;j++)
			{//age of son
				if(dezi+j+4==i&&j==i/2&&i%2==0)
				{
					printf("When his son died, he is %d years old.",i-4);
					return 0;
				}
			}
		}
	}
}
