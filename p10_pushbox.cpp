#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define row 7
#define col 7
int map[row+1][col+1],times=1,score=0;
void readmap() {
	FILE* a;
	if (times == 1)a = fopen("map1.txt", "r");
	if (times == 2)a = fopen("map2.txt", "r");
	if (times == 3)a = fopen("map3.txt", "r");
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			fscanf(a, "%d", &map[i][j]);
	fclose(a);
}
void drawMap()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			
			switch (map[i][j])
			{
				case 0:
				printf("  ");
				break;
			case 1:
				printf("▆");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("★");
				break;
			case 5:
			case 8:
				printf("※");
				break;
			case 7:
				printf("⊙");
				break;
			}
		}
		printf("\n");
	}
}
void move()
{
	
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				break;
			}
		}
		if (map[i][j] == 5 || map[i][j] == 8)
		{
			break;
		}
	}

	char ch = _getch();	
	switch (ch)
	{
		

	case 72:
		
		if (map[i - 1][j] == 0 || map[i - 1][j] == 3)
		{
			
			map[i - 1][j] += 5;
			
			map[i][j] -= 5;
		}
		
		else if (map[i - 1][j] == 4 || map[i - 1][j] == 7)
		{
			
			if (map[i - 2][j] == 0 || map[i - 2][j] == 3)
			{
				
				map[i - 2][j] += 4;
				
				map[i - 1][j] += 1;
				
				map[i][j] -= 5;
			}

		}
		score++;
		break;

	case 80:
		
		if (map[i + 1][j] == 0 || map[i + 1][j] == 3)
		{
			map[i + 1][j] += 5;
			map[i][j] -= 5;
		}
		else if (map[i + 1][j] == 4 || map[i + 1][j] == 7)
		{
			
			if (map[i + 2][j] == 0 || map[i + 2][j] == 3)
			{
				
				map[i + 2][j] += 4;
				map[i + 1][j] += 1;
				map[i][j] -= 5;
			}
		}score++;
		break;
	case 75:
		
		if (map[i][j - 1] == 0 || map[i][j - 1] == 3)
		{
			map[i][j - 1] = map[i][j - 1] + 5;
			map[i][j] = map[i][j] - 5;
		}
		else if (map[i][j - 1] == 4 || map[i][j - 1] == 7)
		{
			if (map[i][j - 2] == 0 || map[i][j - 2] == 3)
			{
			map[i][j - 2] += 4;
			map[i][j - 1] += 1;
			map[i][j] -= 5;
			}
		}
		score++;
		break;
	
	case 77:
		
		if (map[i][j + 1] == 0 || map[i][j + 1] == 3)
		{
		map[i][j + 1] += 5;
		map[i][j] -= 5;
		}
	else if (map[i][j + 1] == 4 || map[i][j + 1] == 7)
		{
			if (map[i][j + 2] == 0 || map[i][j + 2] == 3)
			{
				map[i][j + 2] += 4;
				map[i][j + 1] += 1;
				map[i][j] -= 5;
			}	
		}
		score++;
		break;
	}
}			
int gameOver()
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j <col; j++)
		{
			if (map[i][j] == 7)
				count++;
		}
	}
	return count;
}
int main()
{
	
	for (int i = 1; i <= 3; i++) {
		readmap();
		while (1)
		{
			printf("第【%d】关\n", times);
			drawMap();
			if (gameOver() == 3)break;
			move();
			system("cls");
		}
		times++;
		system("cls");
	}	
	system("cls");
	printf("您的分数是%d",score);
	system("pause");
	return 0;
}