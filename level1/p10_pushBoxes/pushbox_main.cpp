#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h>
int main(int argc, char *argv[])
{
	int x,y,nkey,x0,y0,step,n;
	char key;
	char *a[100];
	int i,j;
	for(i=0;i<15;i++)
	{
		a[i] = (char*)malloc(sizeof(char)*100);
	}
	step=-1;//一开始会把回车键算进去，所以从-1开始而不是从0开始 
	printf("推箱子小游戏，w,s,a,d上下左右，按ESC可退出，你是“o”\n"); 
	printf("把箱子“B”移动到“D”上即可\n");
	printf("按数字1，2选关:");
	scanf("%d",&n);
	FILE *fpRead;
	if(n==1)
	{
		fpRead=fopen("boxmap1.txt","r");
	} 
	else
	{
		fpRead=fopen("boxmap2.txt","r");
	}
	if(fpRead==NULL)
	{
		return 0;
	}
	for(int i=0;i<15;i++)
	{
		fscanf(fpRead,"%s",a[i]);
		for(j=0;j<20;j++)
		{
			if(a[i][j]=='#')
	        	a[i][j]=' ';
		}
	}
	system("cls");
	printf("按回车键开始\n");
	x=7;y=9;
	x0=7;y0=9;
	while(true)
	{
		if((a[2][4]=='B')&&(a[2][13]=='B')&&(a[11][4]=='B')&&(a[11][13]=='B'))
		{
			system("cls"); 
			printf("恭喜你推完了箱子！！\n");
			printf("移动步数：%d\n",step);
			break; 
		} 
		point:key=getch();nkey=(int)key;step++;
		if(nkey==27)break;
		switch(key)
		{
		   case 'w':
		   	{
   			    if(a[x-1][y]=='X')goto point;
			    if((x>0)&&(a[x-1][y]!='X'))
				{
                	if(a[x-1][y]=='B')
    				{ 
       					if(a[x-2][y]=='X')goto point;
			   			x--;
				   		a[x0][y0]=' ';
				   		a[x][y]='o';
				   		a[x-1][y]='B';
				   		x0=x;y0=y;
					    break;
     				}
     				else
     				{
				        	x--;
				   			a[x0][y0]=' ';
				   			a[x][y]='o';
				   			x0=x;y0=y;
					    	break;
				        }
				    }
   		    }
   		    case 'a':
		   	{
   			    if(a[x][y-1]=='X')goto point;
				   if((y>0)&&(a[x][y-1]!='X'))
   			    {
   			    	if(a[x][y-1]=='B')
   			    	{
   			    		if(a[x][y-2]=='X')goto point;
	    			   	y--;
			        	a[x0][y0]=' ';
			        	a[x][y-1]='B';
				   		a[x][y]='o';
				   		x0=x;y0=y;
    			    }
					else
					{
						y--;
			        	a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					}  
					break;
			    } 
   		    }
   		    case 'd':
		   	{
			   if(a[x][y+1]=='X')goto point;
			   if(a[x][y+1]!='X')
   			    {
   			    	if(a[x][y+1]=='B')
   			    	{
   			    		if(a[x][y+2]=='X')goto point;
	    			   	y++;
				   		a[x0][y0]=' ';
				   		a[x][y+1]='B';
				   		a[x][y]='o';
				   		x0=x;y0=y;
    			    }
			        else
			        {
        				y++;
				   		a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
        			}
				   break;
			    } 
   		    }
   		    case 's':
		   	{
   			    if(a[x+1][y]=='X')goto point;
				   if(a[x+1][y]!='X')
			    {
			    	if(a[x+1][y]=='B')
			    	{
			    		if(a[x+2][y]=='X')goto point;
	    				x++;
			    		a[x0][y0]=' ';
			    		a[x+1][y]='B';
				   		a[x][y]='o';
				   		x0=x;y0=y;
	    			}
					else
					{
						x++;
			    		a[x0][y0]=' ';
				   		a[x][y]='o';
				   		x0=x;y0=y;
					}
					
					break;
				}
   		    }defalt:break;
		}	
		system("cls");printf("迷宫小游戏，w,s,a,d上下左右，按ESC可退出\n");
        printf("找不到自己？上下走动试试！\n");
        printf("把箱子“B”移动到“D”上即可\n");
		printf("移动步数：%d\n",step); 
		for(i=0;i<15;i++)
		{
			printf("%s\n",a[i]);
		}
	}
    system("pause");
	return 0;
}