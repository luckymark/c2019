#include"dec.h"
struct point player;
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
		printm();
		indir();
	}
	cls();
	printm();
	printf("Congratulations!\n");
	return 0;
}
