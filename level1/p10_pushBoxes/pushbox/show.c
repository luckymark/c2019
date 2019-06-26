#include"show.h"
void print()
{
	int i, j;
	int temp;
	for (i = 0; i < Maplong; i++)
	{
		for (j = 0; j < Mapwidth; j++)
		{
			if (i == position_x && j == position_y)
			{
					temp = map[i][j];
					px = i;
					py = j;
				map[i][j] = 4;
			}
			switch (map[i][j])
			{
			case(0):
				printf("¡õ");//¡ö¡õ¡ð¨wÇ½
				break;
			case(1):
				printf("  ");//¿ÕµØ
				break;
			case(2):
				printf("¡ö");//BOX
				break;
			case(4):
				printf("¡ð");//ÈËÎï
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	map[px][py] = temp;
	printf("\n");

}