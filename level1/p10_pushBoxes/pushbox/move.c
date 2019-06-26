#include "move.h"

void boxmove()
{
	int temp1;
	if (map[box_x][box_y] == 2)//1ø’µÿ 2box 4»ÀŒÔ
	{
		if (map[box_x + 1][box_y] == 1 &&px==box_x - 1&&py==box_y && direction == 1)
		{
			temp1 = box_x;
			box_x++;
			map[box_x][box_y] = 2;
			map[temp1][box_y] = 1;
		}
		if (map[box_x - 1][box_y] == 1 && px==box_x + 1&&py == box_y && direction == 2)
		{
			temp1 = box_x;
			box_x--;
			map[box_x][box_y] = 2;
			map[temp1][box_y] = 1;
		}
		if (map[box_x][box_y + 1] == 1 && py==box_y -1 && px == box_x && direction == 3)
		{
			temp1 = box_y;
			box_y++;
			map[box_x][box_y] = 2;
			map[box_x][temp1] = 1;
		}
		if (map[box_x][box_y - 1] == 1 &&py==box_y + 1 && px == box_x && direction == 4)
		{
			temp1 = box_y;
			box_y--;
			map[box_x][box_y] = 2;
			map[box_x][temp1] = 1;
		}
	}
}
