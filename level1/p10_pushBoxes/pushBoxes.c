#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAXN 50
#define CASES 10

char Maze[MAXN][MAXN];
int h, w, NowX, NowY, Score, Record;
int AimNum, AimX[5], AimY[5];

int CheckStatus(int x, int y)
{
	if (Maze[x][y] == '#')return 0;
	else if (Maze[x][y] == 'o')return 1;
	return 2;
}

void PrintMaze(int _case)
{
	int flag;
	printf("Case#%d begins,your game record is %d\n", _case, Record);
	for (int i = 0; i <= h + 1; ++i)
	{
		for (int j = 0; j <= w + 1; ++j)
		{
			if (i == NowX && j == NowY)printf("S");
			else if (Maze[i][j] != 'o')
			{
				flag = 0;
				for (int k = 1; k <= AimNum; ++k)
				{
					if (i == AimX[k] && j == AimY[k])
					{
						printf("O");
						flag = 1;
					}
				}
				if (!flag)printf("%c", Maze[i][j]);
			}
			else printf("%c", Maze[i][j]);
		}
		printf("\n");
	}
}

int GameFin()
{
	for (int i = 1; i <= AimNum; ++i)
	{
		if (Maze[AimX[i]][AimY[i]] != 'o')
			return 0;
	}
	return 1;
}

void ReadMapFromFile(int _case)
{
	FILE *fp;
	unsigned char ch;
	char FileName[20];
	sprintf(FileName, ".\\maps\\%d.txt", _case);
	fp = fopen(FileName, "r");
	fscanf(fp, "%d %d%c", &h, &w, &ch);
	for (int i = 0; i <= h + 1; ++i)
	{
		for (int j = 0; j <= w + 1; ++j)
		{
			fscanf(fp, "%c", &Maze[i][j]);
			if (Maze[i][j] == 'O')
			{
				++AimNum;
				AimX[AimNum] = i;
				AimY[AimNum] = j;
			}
		}
		fscanf(fp, "%c", &ch);
	}
	fscanf(fp, "%d", &Record);
	fclose(fp);
}

void GetCopy(int _case)
{
	FILE *fp;
	char FileName[20];
	sprintf(FileName, ".\\maps\\%d.swp", _case);
	fp = fopen(FileName, "w");
	fprintf(fp, "%d %d\n", h, w);
	for (int i = 0; i <= h + 1; ++i)
		fprintf(fp, "%s\n", Maze[i]);
	fclose(fp);
}

void AddScore(int _case, int _score)
{
	FILE *fp;
	char FileName_1[20], FileName_2[20];
	sprintf(FileName_1, ".\\maps\\%d.txt", _case);
	sprintf(FileName_2, ".\\maps\\%d.swp", _case);
	fp = fopen(FileName_2, "a+");
	fprintf(fp, "%d", _score);
	fclose(fp);
	remove(FileName_1);
	rename(FileName_2, FileName_1);
}

int main()
{
	unsigned char ch;
	int tx, ty, flag, Score;
	for (int i = 1; i <= CASES; ++i)
	{
		NowX = NowY = 1;
		Score = 300; AimNum = 0;
		ReadMapFromFile(i);
		GetCopy(i);
		PrintMaze(i);
		while (1)
		{
			if (_kbhit())
			{
				ch = _getch();
				if (ch == 224)ch = _getch();
				if (ch == 80) { tx = 1; ty = 0; }
				if (ch == 77) { tx = 0; ty = 1; }
				if (ch == 72) { tx = -1; ty = 0; }
				if (ch == 75) { tx = 0; ty = -1; }
				if (ch == 27)
				{
					AddScore(i, Record);
					return 0;
				}
				flag = CheckStatus(NowX + tx, NowY + ty);
				if (flag == 1)
				{
					flag = CheckStatus(NowX + tx * 2, NowY + ty * 2);
					if (flag == 2)
					{
						Maze[NowX + tx][NowY + ty] = ' ';
						Maze[NowX + tx * 2][NowY + ty * 2] = 'o';
						NowX += tx; NowY += ty;
						Score--;
					}
				}
				else if (flag == 2)
				{
					NowX += tx;
					NowY += ty;
					Score--;
				}
				else continue;
				system("cls");
				PrintMaze(i);
				if (GameFin())break;
			}
		}
		printf("Case#%d Done,your score is %d.\n", i, Score);
		AddScore(i, max(Record, Score));
		while (1)
		{
			if (_kbhit())
			{
				system("cls");
				ch = _getch();
				break;
			}
		}
	}
	return 0;
}
