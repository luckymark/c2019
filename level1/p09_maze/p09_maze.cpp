#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
int main(int argc, char *argv[])
{
	int x,y,nkey,x0,y0;
	char key;
	char *a[100];
	int i,j;
	for(i=0;i<15;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*100);
	}
	
	
	strcpy(a[0],"XXXXXXXXXXXXXXXXXXXXXX");
	strcpy(a[1],"XXXXXXX   X   X       出口");
	strcpy(a[2],"XX   XX X X X X XXXXXX");
	strcpy(a[3],"X  X X  X   X X  XX");
	strcpy(a[4],"X X  X XXXXXX  X XX");
	strcpy(a[5],"X X XX       X X  X");
	strcpy(a[6],"X X   XXXXXX X XX X");
	strcpy(a[7],"X XXX XX   X X X  X");
	strcpy(a[8],"X   X XX X X X X XX");
	strcpy(a[9],"XXX X X  X X X X  X");
	strcpy(a[10],"X   X X X  X X  X X");
	strcpy(a[11],"X XXX X X X  XX   X");
	strcpy(a[12],"X XXX   X   XXXXXXX");
	strcpy(a[13],"XoXXXXXXXXXXXXXXXXX");
	strcpy(a[14],"  <-由此进入");
	x=13;y=1;
	x0=13;y0=1;
	printf("迷宫小游戏，w,s,a,d上下左右，按ESC可退出，你是“o”\n"); 
	printf("按任意键开始"); 
	while(true)
	{
		a[14][1]='X'; 
		point:key=getch();nkey=(int)key;
		if(nkey==27)break;
		if(y>20)
		{
			system("cls"); 
			printf("恭喜你走出迷宫！！");
			break; 
		} 
		switch(key)
		{
		   case 'w':
		   	{
   			    if(a[x-1][y]=='X')goto point;
				   if((x>0)&&(a[x-1][y]!='X'))
				   	{
				        x--;
				   		a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					    break;
				    }
   		    }
   		    case 'a':
		   	{
   			    if(a[x][y-1]=='X')goto point;
				   if((y>0)&&(a[x][y-1]!='X'))
   			    {
   			    	y--;
			        a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					break;
			    } 
   		    }
   		    case 'd':
		   	{
			   if(a[x][y+1]=='X')goto point;
			   if(a[x][y+1]!='X')
   			    {
			       y++;
				   a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
				   break;
			    } 
   		    }
   		    case 's':
		   	{
   			    if(a[x+1][y]=='X')goto point;
				   if(a[x+1][y]!='X')
			    {
					x++;
			    	a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					break;
				}
   		    }defalt:break;
		}	
		system("cls");printf("迷宫小游戏，w,s,a,d上下左右，按ESC可退出\n");
		for(i=0;i<15;i++)
		{
			printf("%s\n",a[i]);
		}
	}
    system("pause");
	return 0;
}