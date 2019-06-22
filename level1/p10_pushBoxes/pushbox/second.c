#include "second.h"
void second()
{
	if (number > 2)
	{
		printf("you finish all congratulating!!!!!");
		exit(1);
	}
	int i, j;
	char ch1[2];
	printf("是否继续? (y/n )\n");
	scanf("%s", ch1);
	if(strcmp(ch1, "y") == 0)
	{
		printf("第二关地图已生成\n");
		if (freopen("text1.txt", "r", stdin) == NULL)
			printf("error");
		for (i = 0; i < Maplong; i++)
		{
			for (j = 0; j < Mapwidth; j++)
			{
				scanf("%d", &map[i][j]);
				rmap[i][j] = map[i][j];
				if (map[i][j] == 2)
				{
					box_x = i;
					box_y = j;
				}
			}
		}
		position_x = 1;
		position_y = 0;
		freopen("CON", "r", stdin);
	}
	if (strcmp(ch1, "n") == 0)
	{
		exit(1);
	}
}