#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int i,j;
void draw_map(int map[10][12]);
int main()
{
	char input;
	int count=0;
	int map[10][12] = {
		{2,2,2,2,2,1,1,1,1,1,2,2},
		{1,1,1,1,2,1,0,0,0,1,1,2},
		{1,0,0,1,1,1,0,1,0,0,1,2},
		{1,0,4,3,3,3,3,3,1,0,1,1},
		{1,0,0,1,1,3,3,3,4,0,0,1},
		{1,0,0,0,0,4,1,1,4,1,0,1},
		{1,0,4,1,4,0,0,0,4,0,0,1},
		{1,1,0,6,0,1,1,1,4,1,0,1},
		{2,1,1,1,1,1,2,1,0,0,0,1},
		{2,2,2,2,2,2,2,1,1,1,1,1}
	};
	while (1)
	{
		system("CLS");
		printf("\n");
		printf("\n");
		draw_map(map);
		printf("当前得分：%d\n",count);
		for (i=0;i<10;i++)
		{
			for (j=0;j<12;j++)
			{
				if (map[i][j]==6||map[i][j]==9)
					break;
			}
			if (map[i][j]==6||map[i][j]==9)
				break;
		}
		printf("您的当前坐标（%d，%d）",i,j);
		input = getch();
		switch (input)
		{
		case 'w':
			if(map[i-1][j]==0)
			{
				map[i-1][j]=6+0;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if((map[i-1][j]==3)||(map[i-1][j]==9))
			{
				map[i-1][j]=6+3;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i-1][j]==4)
			{
				if (map[i-2][j]==0)
				{
					map[i-2][j]=4;
					if(map[i-1][j]==7)
						map[i-1][j]=9;
					else
						map[i-1][j]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				else if (map[i-2][j]==3)
				{
					map[i-2][j]=7;
					count++;
					if(map[i-1][j]==7)
						map[i-1][j]=9;
					else
						map[i-1][j]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			else if(map[i-1][j]==7)
			{
				if(map[i-2][j]==0)
				{
					count--;
					map[i-2][j]=4;
					map[i-1][j]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				if(map[i-2][j]==3)
				{
					map[i-2][j]=7;
					map[i-1][j]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 's':
			if(map[i+1][j]==0)
			{
				map[i+1][j]=6+0;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i+1][j]==3)
			{
				map[i+1][j]=6+3;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i+1][j]==4)
			{
				if (map[i+2][j]==0)
				{
					map[i+2][j]=4;
					if(map[i+1][j]==7)
						map[i+1][j]=9;
					else
						map[i+1][j]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				else if (map[i+2][j]==3)
				{
					map[i-2][j]=7;
					count++;
					if(map[i+1][j]==7)
						map[i+1][j]=9;
					else
						map[i+1][j]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			else if(map[i+1][j]==7)
			{
				if(map[i+2][j]==0)
				{
					count--;
					map[i+2][j]=4;
					map[i+1][j]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				if(map[i+2][j]==3)
				{
					map[i+2][j]=7;
					map[i+1][j]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 'a':
			if(map[i][j-1]==0)
			{
				map[i][j-1]=6+0;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i][j-1]==3)
			{
				map[i][j-1]=6+3;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i][j-1]==4)
			{
				if (map[i][j-2]==0)
				{
					map[i][j-2]=4;

					if(map[i][j-1]==7)
						map[i][j-1]=9;
					else
						map[i][j-1]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				else if (map[i][j-2]==3)
				{
					count++;
					map[i][j-2]=7;
					if(map[i][j-1]==7)
						map[i][j-1]=9;
					else
						map[i][j-1]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			else if(map[i][j-1]==7)
			{
				if(map[i][j-2]==0)
				{
					count--;
					map[i][j-2]=4;
					map[i][j-1]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				if(map[i][j-2]==3)
				{
					map[i][j-2]=7;
					map[i][j-1]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		case 'd':
			if(map[i][j+1]==0)
			{
				map[i][j+1]=6+0;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}

			else if(map[i][j+1]==3)
			{
				map[i][j+1]=6+3;
				if(map[i][j]==9)
					map[i][j]=3;
				else
					map[i][j]=0;
			}
			else if(map[i][j+1]==4)
			{
				if (map[i][j+2]==0)
				{
					map[i][j+2]=4;
					if(map[i][j+1]==7)
						map[i][j+1]=9;
					else
						map[i][j+1]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				else if (map[i][j+2]==3)
				{
					count++;
					map[i][j+2]=7;
					if(map[i][j+1]==7)
						map[i][j+1]=9;
					else
						map[i][j+1]=6;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			else if(map[i][j+1]==7)
			{
				if(map[i][j+2]==0)
				{
					count--;
					map[i][j+2]=4;
					map[i][j+1]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
				if(map[i][j+2]==3)
				{
					map[i][j+2]=7;
					map[i][j+1]=9;
					if(map[i][j]==9)
						map[i][j]=3;
					else
						map[i][j]=0;
				}
			}
			break;
		}
		if(count==8)
		{
			system("CLS");
			draw_map(map);
			break;
		}
	}
	printf("\n恭喜你，过关了！！\n");
	return 0;
}
void draw_map(int map[10][12])
{

	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
		{
			switch(map[i][j])
			{
			case 0:
				printf(" ");
				break;
			case 1:
				printf("#");
				break;
			case 2:
				printf(" ");
				break;
			case 3:
				printf("!");
				break;
			case 4:
				printf("*");
				break;
			case 7:
				printf("$");
				break;
			case 6:
				printf("@");
				break;
			case 9:
				printf("@");
				break;
			}
		}
		printf("\n");
	}
}


