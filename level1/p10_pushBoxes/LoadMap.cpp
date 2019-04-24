#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int LoadMap(int n, char Map[][15]);

int LoadMap(int n, char Map[][15])
{
	int i = 0;
	switch (n)
	{
	case 1:
		FILE *fp;
		fp = fopen("1.txt", "r");
		if (fp == NULL)
		{
			printf("Something wrong!\n");
			system("pause");
			return 0;
		}
		while (!feof(fp))
		{
			fgets(Map[i], 15, fp);
			++i;
		}
		fclose(fp);
		return i;
		break;
	case 2:
		fp = fopen("2.txt", "r");
		if (fp == NULL)
		{
			printf("Something wrong!\n");
			return 0;
		}
		while (!feof(fp))
		{
			fgets(Map[i], 15, fp);
			++i;
		}
		fclose(fp);
		return i;
		break;
	case 3:
		fp = fopen("3.txt", "r");
		if (fp == NULL)
		{
			printf("Something wrong!\n");
			return 0;
		}
		while (!feof(fp))
		{
			fgets(Map[i], 15, fp);
			++i;
		}
		fclose(fp);
		return i;
		break;
	case 4:
		fp = fopen("4.txt", "r");
		if (fp == NULL)
		{
			printf("Something wrong!\n");
			return 0;
		}
		while (!feof(fp))
		{
			fgets(Map[i], 15, fp);
			++i;
		}
		fclose(fp);
		return i;
		break;
	case 5:
		fp = fopen("5.txt", "r");
		if (fp == NULL)
		{
			printf("Something wrong!\n");
			return 0;
		}
		while (!feof(fp))
		{
			fgets(Map[i], 15, fp);
			++i;
		}
		fclose(fp);
		return i;
		break;
	}
}