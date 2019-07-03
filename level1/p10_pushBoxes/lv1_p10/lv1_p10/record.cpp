#include<stdio.h>

extern int score;

void record(int n)
{
	FILE *fp = NULL;
	fopen_s(&fp, "score.txt", "rt+");
	if (n == 1)
	{
		fprintf(fp, "Map1 final score:%d", score);
	}
	else if (n == 2)
	{
		fprintf(fp, "Map2 final score:%d", score);
	}
	else if (n == 3)
	{
		fprintf(fp, "Map3 final score:%d", score);
	}
	fclose(fp);
}