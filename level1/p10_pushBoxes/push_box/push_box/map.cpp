#include"map.h"
void print(char(*map)[15])
{
	int i, j;
	for (i = 0;i<15; i++)
	{
		putchar('\t');
		for (j = 0;j<15; j++)
		{
			putchar(map[i][j]);
		}
		putchar('\n');
	}
	return;
}

void loadmap(int number, char(*map)[15])
{
	if (number == 1)
	{
		FILE*fp = fopen("map1.txt", "r");
		int i, j;
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
			{
				fread(&map[i][j], sizeof(map[0][0]), 1, fp);
			}
		}
		fclose(fp);
	}
	if (number == 2)
	{
		FILE*fp = fopen("map2.txt", "r");
		int i, j;
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
			{
				fread(&map[i][j], sizeof(map[0][0]), 1, fp);
			}
		}
		fclose(fp);
	}
	
}