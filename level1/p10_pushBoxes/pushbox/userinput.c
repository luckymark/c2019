#include"useinput.h"

void userinput(char ch)
{
	int i,j;
	if (ch == 'w')
	{
		position_x--;
		direction = 2;
		scorenumber++;
		if (map[position_x][position_y] == 0||(map[position_x][position_y]==2  &&map[position_x-1][position_y]==0))
		{
			position_x++;
			scorenumber--;
			direction = 0;
		}
	}
	if (ch == 's')
	{
		position_x++;
		direction = 1;
		scorenumber++;
		if (map[position_x][position_y] == 0 || (map[position_x][position_y] == 2 && map[position_x + 1][position_y] == 0))
		{
			position_x--;
			scorenumber--;
			direction = 0;
		}
	}
	if (ch == 'a')
	{
		direction = 4;
		position_y--;
		scorenumber++;
		if (map[position_x][position_y] == 0 || (map[position_x][position_y] == 2 && map[position_x ][position_y-1] == 0))
		{
			position_y++;
			scorenumber--;
			direction = 0;
		}
	}
	if (ch == 'd')
	{
		position_y++;
		direction = 3;
		scorenumber++;
		if (map[position_x][position_y] == 0 || (map[position_x][position_y] == 2&& map[position_x ][position_y+1] == 0))
		{
			position_y--;
			scorenumber--;
			direction = 0;
		}
	}
	if (ch == 'r')
	{
		for (i = 0; i < Maplong; i++)
		{
			for (j = 0; j < Mapwidth; j++)
			{
				
				map[i][j] = rmap[i][j];
				if (rmap[i][j] == 2)
				{
					box_x = i;
					box_y = j;
					position_x = 1;
					position_y = 0;
				}
			}
		}
	}
}
