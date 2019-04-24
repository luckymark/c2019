#include <stdio.h>
#include <stdlib.h>

void SaveScore(int i, int score);

void SaveScore(int i, int score)
{
	FILE *fp;
	switch (i)
	{
	case 1:fp = fopen("score1.txt", "w"); break;
	case 2:fp = fopen("score2.txt", "w"); break;
	case 3:fp = fopen("score3.txt", "w"); break;
	case 4:fp = fopen("score4.txt", "w"); break;
	case 5:fp = fopen("score5.txt", "w"); break;
	}
	if (fp == NULL)
	{
		printf("Something wrong!\n");
		system("pause");
		return;
	}
	fprintf(fp, "Your score in level %d is %d...", i, score);
	printf("Your score in level %d is %d...\n", i, score);
	fclose(fp);
	return;
}