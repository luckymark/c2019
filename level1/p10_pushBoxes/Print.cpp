#include <cstdio>
#include "game.h"

void PrintSpace(int x, int y);

void PrintX(int x, int y);

void PrintO(int x, int y);

void PrintD(int x, int y);

void PrintSpace(int x, int y)
{
	SetPosition(x, y);
	printf(" ");
}

void PrintX(int x, int y)
{
	SetPosition(x, y);
	printf("X");
}

void PrintO(int x, int y)
{
	SetPosition(x, y);
	printf("O");
}

void PrintD(int x, int y)
{
	SetPosition(x, y);
	printf("D");
}