#include<stdio.h>
#include"gomoku.h"
int main()
{
	drawmap();
	showmap();
	int i;
	
	map[7][7]='0';
	system("cls");
	showmap();//¿ª¾Ö
	
	
	for(i=2;;i++)
	{
        int a,b;
		if(i%2==1)
		{
			int x,y;
			computer(&x,&y);
			a=x;b=y;
		}
		else scanf("%d %d",&a,&b);
		if(a>=0&&a<=15&&b>=0&&b<=15)
		{
            if(map[a][b]!='+')
		    {
			    i--;
		    }
		    if(i%2==1&&map[a][b]=='+')
		    {
			    map[a][b]='0';
	     	}
		    else if(i%2==0&&map[a][b]=='+')
		    {
			    map[a][b]='&';
		    }
		    system("cls");
		    showmap();
        }
        else
        {
        	i--;
		}

		if(judge(a,b))
		{
			if(map[a][b]=='0')
			{
				printf("You lose it!");
			}
			else
			{
				printf("You win it!");
			}
			break;
		}
		
	}
	return 0;
}
