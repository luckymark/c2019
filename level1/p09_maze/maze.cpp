#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAPM 10
#define MAPN 21
#define NAME F
struct point
{
	int x;
	int y;
}player;
char map[MAPM][MAPN]={"####################",
					  "#  #    #        # #",
					  "##  # ##  # ###    #",
					  "#  ## #  ### # ## ##",
					  "#     #  # # #  #  #",
					  "# ###   #    ##  ###",
					  "#   #  #  ##  #  # #",
					  "# ##   # # #       #",
					  "# #  #   #   ##  #E#",
					  "####################"};
char playerpos[MAPM][MAPN];						//player's position
void cls();										//clear screen
void clm(char map[MAPM][MAPN]);					//clear map
void creatm(char map[MAPM][MAPN]);				//creat map
void printm(char map[MAPM][MAPN]);				//print map
void indir();									//input direction
int main()
{
	int i,j;
	player.x=1;
	player.y=1;
	clm(playerpos);
	playerpos[player.y][player.x]='P';
	while(map[player.y][player.x]!='E')
	{
		cls();
		printm(map);
		indir();
	}
	cls();
	printm(map);
	printf("Congratulations!\n");
	return 0;
}
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
void creatm(char map[MAPM][MAPN])
{
}
void printm(char map[MAPM][MAPN])
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
	getch();
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
	}
}
