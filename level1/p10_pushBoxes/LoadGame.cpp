#include <stdio.h>
#include <stdlib.h>

int LoadGame();

int LoadGame()
{
	FILE *fp;
	fp = fopen("Save.txt", "r");
	if (fp == NULL)
	{
		printf("Something wrong!\n");
		system("pause");
		return 0;
	}
	int i = (int)fgetc(fp) - 48;
	fclose(fp);
	return i;
}