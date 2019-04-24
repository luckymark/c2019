#include <stdio.h>
#include <stdlib.h>

void Save(int i);

void Save(int i)
{
	FILE *fp;
	fp = fopen("Save.txt", "w");
	if (fp == NULL)
	{
		printf("Something wrong!\n");
		system("pause");
		return;
	}
	fputc(i + 48, fp);
	fclose(fp);
	return;
}