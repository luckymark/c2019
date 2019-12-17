#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
	int y=1,x=1;
	int maze[11][11]=
	{
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,8,1,0,0,0,0,0,0,0,1},
		{1,0,1,0,1,0,1,1,1,0,1},
		{1,0,1,0,1,0,1,0,0,0,1},
		{1,0,0,0,1,0,1,0,1,1,1},
		{1,1,1,1,1,0,1,0,1,2,1},
		{1,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1}
	};
	
	while(maze[5][9]==2)
	{
		for(int i=0,j=0;i<11;++i)
		{
			for(;j<11;++j)
			{
				if(maze[i][j]==0)
					printf(" ");
				if(maze[i][j]==1)
					printf("#");
				if(maze[i][j]==2)
					printf("C");
				if(maze[i][j]==8)
					printf("Y");
			}
				if(j==11)
				{
					j=0;
					printf("\n");
				}
		}
		char move=_getch();
		if(move==75&&maze[y][x-1]!=1)
		{
			maze[y][x]=0;
			maze[y][x-1]=8;
			x-=1;
		}
		if(move==77&&maze[y][x+1]!=1)
		{
			maze[y][x]=0;
			maze[y][x+1]=8;
			x+=1;
		}
		if(move==72&&maze[y-1][x]!=1)
		{
			maze[y][x]=0;
			maze[y-1][x]=8;
			y-=1;
		}
		if(move==80&&maze[y+1][x]!=1)
		{
			maze[y][x]=0;
			maze[y+1][x]=8;
			y+=1;
		}
		system("cls");
	}
	printf("You win!!!\n");
	return 0;
}
