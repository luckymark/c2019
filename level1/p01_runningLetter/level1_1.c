#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define WIDTH 20
int main()
{
	int x,y,z,s,w;
	char a[WIDTH];
	for(x=1;x<=100;x++)
		
	{
	if (x%2==1)
	    {
		w=1;	
		}
	else
		{
		w=-1;
		}
	{for(y=WIDTH*(1-w)/2;y!=WIDTH*(1+w)/2;y+=w)
		{for(z=0;z<y;z++)			
			{
			putchar(' ');
		    }
		printf("%c\n",'A');
		Sleep(100);
		system("cls");	
		}
	}
	
	}
}
