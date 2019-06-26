#include "allcalculate.h"
#include"calculate.h"
int allcalculate()
{
	int i, j, k;
	int score = 0;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < length; j++)
		{
			board1[j] = board[i][j];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	for (j = 0; j < length; j++)
	{
		for (i = 0; i < width; i++)
		{
			board1[i] = board[i][j];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	for (i = 4; i < width; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			board1[j] = board[i - j][j];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	for (i = width - 5; i > 0; i--)
	{
		for (j = 0; j < length - i; j++)
		{
			board1[j] = board[i + j][j];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	for (j = length - 5; j > -1; j--)
	{
		for (i = 0; i < width - j; i++)
		{
			board1[i] = board[i][j + i];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	for (j = 1; j < length - 4; j++)
	{
		for (i = width - 1; i > j - 1; i--)
		{
			board1[width - i - 1] = board[i][width + j - 1 - i];
		}
		score += calculate(board1) + anticalculate(board1);
		for (k = 0; k < 15; k++)
		{
			board1[k] = 5;
		}
	}
	//printf("%d\n",score );
	return score;
}