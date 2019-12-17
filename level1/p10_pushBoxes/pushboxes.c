#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main()
{
	int flag=1;
	int x,y,steps=0;
	int gift[11][11];
	int maze[11][11]=
	{
		{1,1,1,1,1,1,1,1,1,1,1},
		{1,0,8,0,0,0,0,0,0,0,1},
		{1,0,3,0,0,0,0,0,0,0,1},
		{1,0,3,0,1,0,1,0,0,0,1},
		{1,0,0,0,1,0,1,0,1,1,1},
		{1,1,1,1,1,0,1,0,1,2,1},
		{1,2,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,0,0,1},
		{1,0,0,0,1,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1,1}
	};

	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			if(maze[i][j]==2)
				gift[i][j]=1;
			else
				gift[i][j]=0;
			if(maze[i][j]==8)
			{
				y=i;
				x=j;
			}
		}
	}
	
	printf("推箱子\n按任意键游玩，按E退出\nWASD键控制\n");
	char play=_getch();
	while(play=='e')
	{
		system("cls");
		printf("还是玩一下吧？\n按任意键游玩，按E退出\n");
		play=_getch();
	}
	system("cls");
	
	while(flag)
	{
		for(int i=0;i<11;++i)
		{
			for(int j=0;j<11;++j)
			{
				if(maze[i][j]==2)
					printf("C");
				if(maze[i][j]==0)
					printf(" ");
				if(maze[i][j]==1)
					printf("#");
				if(maze[i][j]==8)
					printf("Y");
				if(maze[i][j]==3)
					printf("O");
				if(j==10)
				{
					printf("\n");
				}
			}
		}
		
		char move=_getch();
		if(move=='a')//left
		{
			if(maze[y][x-1]==0||maze[y][x-1]==2)
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y][x-1]=8;
				x--;
				steps++;
			}
			else if(maze[y][x-1]==3&&(maze[y][x-2]!=1&&maze[y][x-2]!=3))
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y][x-1]=8;
				maze[y][x-2]=3;
				x--;
				steps++;
			}
		}
		if(move=='d')//right
		{
			if(maze[y][x+1]==0||maze[y][x+1]==2)
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y][x+1]=8;
				x++;
				steps++;
			}
			else if(maze[y][x+1]==3&&(maze[y][x+2]!=1&&maze[y][x+2]!=3))
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y][x+1]=8;
				maze[y][x+2]=3;
				x++;
				steps++;
			}
		}
		if(move=='w')//up
		{
			if(maze[y-1][x]==0||maze[y-1][x]==2)
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y-1][x]=8;
				y--;
				steps++;
			}
			else if(maze[y-1][x]==3&&(maze[y-2][x]!=1&&maze[y-2][x]!=3))
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y-1][x]=8;
				maze[y-2][x]=3;
				y--;
				steps++;
			}
		}
		if(move=='s')//down
		{
			if(maze[y+1][x]==0||maze[y+1][x]==2)
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y+1][x]=8;
				y++;
				steps++;
			}
			else if(maze[y+1][x]==3&&(maze[y+2][x]!=1&&maze[y+2][x]!=3))
			{
				if(gift[y][x]==1)
					maze[y][x]=2;
				else
					maze[y][x]=0;
				maze[y+1][x]=8;
				maze[y+2][x]=3;
				y++;
				steps++;
			}
		}
		
		system("cls");
		
		flag=0;
		for(int i=0;i<11;++i)
		{
			for(int j=0;j<11;++j)
			{
				if(gift[i][j]==1&&maze[i][j]!=3)
				{
					flag=1;
				}
			}
		}
	}
	printf("You win!!!\nand you used %d steps\n",steps);
	getchar();
}
