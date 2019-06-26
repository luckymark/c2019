#include"exam.h"
int exam()//≈–∂œ §∏∫
{
	int i;
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y] == 2||board[userposition_x+i][userposition_y ] == 5)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 2;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x][userposition_y + i] == 2 || board[userposition_x][userposition_y + i] == 5)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 2;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y + i] == 2 || board[userposition_x+i][userposition_y + i] == 5)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 2;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y - i] == 2 || board[userposition_x+i][userposition_y - i] == 5)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 2;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y] == 4)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 4;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x][userposition_y + i] == 4  )
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 4;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y + i] == 4 )
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			return 4;
		}
	}
	for (i = -4; i < 5; i++)
	{
		if (board[userposition_x + i][userposition_y - i] == 4 )
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (5 == count)
		{
			return 4;
		}
	}
	return 0;
}