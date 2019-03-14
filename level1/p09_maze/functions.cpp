#include"dec.h"
void cls()
{
	system("cls");
}
void clm(char map[MAPM][MAPN])
{
	int x,y;
	for(x=0;x<MAPM;++x)
		for(y=0;y<MAPN;++y)
			map[x][y]=' ';
}
void creatm()
{
}
void printm()
{
	int x,y;
	for(x=0;x<MAPM;++x)
		for(y=0;y<MAPN;++y)
		{
			if(map[x][y]!=' ')
				putchar(map[x][y]);
			else
				putchar(playerpos[x][y]);
			if(y==MAPN-1)
				putchar('\n');
		}
}
void indir()
{
	while(getch()!=224);
	switch(getch())
	{
		case 72:if(map[player.y-1][player.x]!='#')				//up
				{
					playerpos[player.y][player.x]=' ';
					player.y-=1;
					playerpos[player.y][player.x]='P';
				}
				break;
		case 80:if(map[player.y+1][player.x]!='#')				//down
				{
					playerpos[player.y][player.x]=' ';
					player.y+=1;
					playerpos[player.y][player.x]='P';
				}
				break;
		case 75:if(map[player.y][player.x-1]!='#')				//left
				{
					playerpos[player.y][player.x]=' ';
					player.x-=1;
					playerpos[player.y][player.x]='P';
				}
				break;
		case 77:if(map[player.y][player.x+1]!='#')				//right
				{
					playerpos[player.y][player.x]=' ';
					player.x+=1;
					playerpos[player.y][player.x]='P';
				}
				break;
		default:;												//for warning:assert...
	}
}
