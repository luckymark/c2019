#include "exam.h"
int  exam()
{
	if (box_x == out_x && box_y == out_y)
	{
		printf("you win \n");
		number++;
		return 1;
	}
	return 0;
}