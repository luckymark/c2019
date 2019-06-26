#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define WIDTH 25
#define LENGTH 25

#define start_point 'S'
#define end_point 'E'
#define wall 'O'
#define temp '*'
#define empty ' '

char maze[LENGTH][WIDTH];
int temp_row,temp_line; 

void initialize(char(*maze_f)[WIDTH])
{
	int i, j;
	for (i = 0; i < LENGTH; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			maze_f[i][j] = wall;
		}
	}
	maze_f[1][0] = start_point;
	temp_row=1;
	temp_line=1;
	maze_f[temp_row][temp_line] = empty;
	
	maze_f[LENGTH - 2][WIDTH - 1] = end_point;//出口坐标
}

void print_maze(char(*maze_f)[WIDTH])
{
	printf("*shows where you are,and you should move to the point 'E'\n");
	int i, j;
	for (i = 0; i<=WIDTH + 1; i++)
	{
		putchar('_');
	}
	putchar('\n');
	for (i = 0; i < LENGTH; i++)
	{
		putchar('|');
		for (j = 0; j < WIDTH; j++)
		{
			putchar(maze[i][j]);
		}
		putchar('|');
		putchar('\n');
	}
	for (i = 0; i <= WIDTH + 1; i++)
	{
		putchar('-');
	}
	
	return;
}

void create(char(*maze)[WIDTH])
//先生成通路，后面随机生成空格干扰 
{
	int direction;
	int i,j,n;
	//if(maze[LENGTH-2][WIDTH-2]!=empty)
	{
		direction=rand()%4;
		switch(direction)
		{
			case 0://UP
				if(maze[temp_row-1][temp_line]!=empty&&temp_row>1)
				{
					temp_row--;
					maze[temp_row][temp_line]=empty;
				}
				break;
			case 1://DOWN
				if(maze[temp_row+1][temp_line]!=empty&&temp_row<LENGTH-2)
				{
					temp_row++;
					maze[temp_row][temp_line]=empty;
				}
				break;
			case 2://LEFT
				if(maze[temp_row][temp_line-1]!=empty&&temp_line>1)
				{
					temp_line--;
					maze[temp_row][temp_line]=empty;
				}
				break;
			case 3://RIGHT
				if(maze[temp_row][temp_line+1]!=empty&&temp_line<WIDTH-2)
				{
					temp_line++;
					maze[temp_row][temp_line]=empty;
				}
				break;
		}
	}

	
}

void move(char(*maze)[WIDTH])
{
	char ch1,ch2,exchange;
	ch1=getch();
	ch2=getch();
	
	switch(ch2)
	{
		case 72://UP
			if(maze[temp_row-1][temp_line]==empty||maze[temp_row-1][temp_line]=='N')
			{
				maze[temp_row-1][temp_line]=temp;
				maze[temp_row][temp_line]=empty;
				temp_row--;	
				system("cls");
				print_maze(maze);
			}
			break;
		case 80://DOWN 
			if(maze[temp_row+1][temp_line]==empty||maze[temp_row+1][temp_line]=='N')
			{
				maze[temp_row+1][temp_line]=temp;
				maze[temp_row][temp_line]=empty;
				temp_row++;	
				system("cls");
				print_maze(maze);
			}
			break;
		case 75://LEFT
			if(maze[temp_row][temp_line-1]==empty||maze[temp_row][temp_line-1]=='N')
			{
				maze[temp_row][temp_line-1]=temp;
				maze[temp_row][temp_line]=empty;
				temp_line--;
				system("cls");	
				print_maze(maze);
			}
			break;
		case 77://RIGHT 
			if(maze[temp_row][temp_line+1]==empty
			||maze[temp_row][temp_line+1]=='N'
			||maze[temp_row][temp_line+1]==end_point)
			{
				maze[temp_row][temp_line+1]=temp;
				maze[temp_row][temp_line]=empty;
				temp_line++;
				system("cls");	
				print_maze(maze);
			}
			break;
	}
}



int main()
{
	int i,j,n;


	
	srand((unsigned)time(NULL));
	while(maze[LENGTH-2][WIDTH-2]!=empty)
	{
	
		initialize(maze);
	
		for(i=0;i<10000;i++)
		{
			create(maze); 
		}
	}
	for(n=0;n<300;n++)
	{
			
		i=rand()%(LENGTH-1);
		j=rand()%(WIDTH-1);	
		if(i!=0&&j!=0)
		{
			maze[i][j]=' ';
		}
	}//随机生成若干个空白 
	
	maze[1][0]=temp;
 
	print_maze(maze);
	temp_row=1;
	temp_line=0;
	
	while(maze[LENGTH-2][WIDTH-1]!=temp) 
	{
		move(maze);
	} 
	printf("\nCONGRATULATIONS!");
	return 0;
}

