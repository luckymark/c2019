#include "Maze.h"
bool area[MAX_LTH][MAX_WTH];
bool Visited[MAX_LTH][MAX_WTH];
bool Mask[MAX_LTH][MAX_WTH];
int dt[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//0 represent x coordinary, 1 represent y coordinary

int main(void)
{
	Pos curpos;//record the curent position of the gamer
	Initposition(&curpos);

	int maze[MAX_LTH][MAX_WTH];//be created to sure the sort of the maze
	brick start, over;
	FormMaze(maze, &start, &over);
	/*GoToxy(curpos.x, curpos.y);
	printf("1"); used to test the GoToxy is work well*/
	// printf("Enter to move:\n");//begin to play the game
	GameAndFun(&curpos, maze);

	system("pause");
	return 0;
}
//funtion1 Form a Maze
void FormMaze(int maze[MAX_LTH][MAX_WTH], brick *start, brick *over)
{
	InitShape();
	srand((unsigned)time(NULL));
	
	int i, j;
	
	for (i=0; i<MAX_LTH; i++)
	{
		for (j=0; j<MAX_WTH; j++)
		{
			if (area[i][j]&&!(area[i][j-1]&&area[i][j+1]&&area[i-1][j]&&area[i+1][j]))
				maze[i][j]=OUTWALL;
			else if (area[i][j] && 0==i%2 && 0==j%2)
				maze[i][j]=ROAD;
			else if (area[i][j] )
				maze[i][j]=INWALL;
			else
				maze[i][j]=EMPTY;
			
			Visited[i][j]=false;
			Mask[i][j]=true;
				
		}	
	}

	start->x=1;
	start->y=6;
	over->x=27;
	over->y=36;
	maze[start->x][start->y]=maze[over->x][over->y]=ROAD;//define the entrance and the exit
	Queue Q;
	InitQueue(&Q);
	
	brick begin;//the begin of the construction of the maze
	begin.x=2;
	begin.y=6;
	
	enqueue(&Q, begin);
	Visited[begin.x][begin.y]=true;
	clearMask(begin.x, begin.y);
	
	while (!QisEmpty(Q))
	{
		brick curbrick;
		dequeue(&Q, &curbrick);
		
		for (i=0; i<4; i++)
		{
			int nextbrickX=curbrick.x+dt[i][0]*2;
			int nextbrickY=curbrick.y+dt[i][1]*2;
			if (InMaze(nextbrickX, nextbrickY)&&ROAD==maze[nextbrickX][nextbrickY] && !Visited[nextbrickX][nextbrickY])
				{
					brick nextbrick;
					nextbrick.x=nextbrickX;
					nextbrick.y=nextbrickY;
					enqueue(&Q, nextbrick);
					maze[curbrick.x+dt[i][0]][curbrick.y+dt[i][1]]=ROAD;
					Visited[nextbrickX][nextbrickY]=true;
					clearMask(nextbrickX, nextbrickY);
					updateMaze(maze);
				}
		}
	}

	for (i=0; i<MAX_LTH; i++)
	{
		for (j=0; j<MAX_WTH; j++)
		{
			if (OUTWALL==maze[i][j])
			{
				Mask[i][j]=false;
				updateMaze(maze);
			}
		}
	}	
}
//funtion2 init the shape of the bounder that bounded the maze
void InitShape(void)
{
	int i=0, j=0;
	float x, y, tmp1, tmp2;
	
	for (y=1.2f; y>-1.0f;y-=0.06f)
	{
		for (x=-1.1f; x<1.2f; x+=0.05f)
		{
			tmp1 =x*x+y*y-1;
			tmp2 =tmp1*tmp1*tmp1-x*x*y*y*y;
			if (tmp2<=0.0f)
				area[i][j]=true;//in the maze marked as true
			else
				area[i][j]=false;//out the maze marked as false
				
			j++;
		}
		i++;
		j=0;
	}
}
//function3 like xpbombs clear the 3*3 areas
void clearMask(int x, int y)
{
	int i, j;
	for (i=x-1; i<x+2; i++)
		for (j=y-1; j<y+2; j++)
			if (InMaze(i, j))
				Mask[i][j]=false;
				
}
//function4 to sure whether the coordinate over the limit area
bool InMaze(int x, int y)
{
	return x>-1 && x<MAX_LTH && y>-1 && y<MAX_WTH;
}
//function5 to show the maze
void updateMaze(int MAZE[MAX_LTH][MAX_WTH])
{
	hideCursor();
	GoToxy(0, 0);
	ShowBrick(MAZE);
	Sleep(SLEEPTIME);
}
//function6 to hide the Cursor
void hideCursor(void)
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};//set the stage to hide the cursor
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//function7 move the cursor to the (x, y)
void GoToxy(int x, int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=y;//because the definition of the console and mine is opposite
	//so I have to let X to be y, and Y to be x.
	pos.Y=x;
	SetConsoleCursorPosition(handle, pos);
	
}
/**
 * [ShowBrick description]draw the brick of the wall
 * @param maze [description] the array of mazem
 */
void ShowBrick(int maze[MAX_LTH][MAX_WTH])
{
	int i, j;
	for (i=0; i<MAX_LTH; i++)
	{
		for (j=0; j<MAX_WTH; j++)
		{
			if (true==Mask[i][j])
				printf(" ");
			else if(INWALL==maze[i][j])
				printf("0");
			else if(OUTWALL==maze[i][j])
				printf("0");
			else if(EMPTY==maze[i][j])
				printf(" ");
			else if(ROAD==maze[i][j])
				printf(" ");
			if (0!=j && 0==j%(MAX_WTH-1))
				printf("\n");
		}
			
	}
}
/**
 * Init the postion of the gamers position
 * @param pos [pointer of curpos]
 */
void Initposition(Pos * pos)
{
	pos->x=1;
	pos->y=6;
}
/**
 * [GameAndFun description]
 * @param curpos [description]
 * @param maze   [description]
 */
void GameAndFun(Pos *curpos, int maze[MAX_LTH][MAX_WTH])
{
	Pos nextpos;//record the coordinate that might be the 
	//next posotion of the gamer
	char oprat;//record the oprat of the move from the console
	printf("Just enjoy the game!");
	printf("Use your keyboard up, down, left, right key.\n");
	printf("Enter n back to the begining, enter q to quit.\n");
	printf("Good Luck!");
	GoToxy(curpos->x, curpos->y);
	printf("1");
	while (27!=curpos->x || 36!=curpos->y )
	{
		oprat=getch();

		if ('q'==oprat)
			break;
		else if ('n'==oprat)
		{
			GoToxy(curpos->x, curpos->y);
			putchar(' ');
			Sleep(SLEEPTIME);
			curpos->x=1;
			curpos->y=6;
			GoToxy(curpos->x, curpos->y);
			putchar('1');
			Sleep(SLEEPTIME);

			continue;
		}
		else if (UP==oprat)
		{
			nextpos.x=curpos->x-1;
			nextpos.y=curpos->y;
			if (InMaze(nextpos.x, nextpos.y) && !Mask[nextpos.x][nextpos.y] 
				&& INWALL != maze[nextpos.x][nextpos.y] 
				&& OUTWALL != maze[nextpos.x][nextpos.y])
			{
				GoToxy(curpos->x, curpos->y);
				printf(" ");
				Sleep(SLEEPTIME);
				curpos->x-=1;
				GoToxy(curpos->x, curpos->y);
				printf("1");
				Sleep(SLEEPTIME);
			}
			else
				continue;
		}
		else if (DOWN==oprat)
		{
			nextpos.x=curpos->x+1;
			nextpos.y=curpos->y;
			if (InMaze(nextpos.x, nextpos.y) && INWALL != maze[nextpos.x][nextpos.y] 
				&& OUTWALL != maze[nextpos.x][nextpos.y])
			{
				GoToxy(curpos->x, curpos->y);
				printf(" ");
				Sleep(SLEEPTIME);
				curpos->x+=1;
				GoToxy(curpos->x, curpos->y);
				printf("1");
				Sleep(SLEEPTIME);
			}
			else
				continue;
		}
		else if (LEFT==oprat)
		{
			nextpos.y=curpos->y-1;
			nextpos.x=curpos->x;
			if (InMaze(nextpos.x, nextpos.y) && INWALL != maze[nextpos.x][nextpos.y] 
				&& OUTWALL != maze[nextpos.x][nextpos.y])
			{
				GoToxy(curpos->x, curpos->y);
				printf(" ");
				Sleep(SLEEPTIME);
				curpos->y-=1;
				GoToxy(curpos->x, curpos->y);
				printf("1");
				Sleep(SLEEPTIME);
			}
			else
				continue;
		}
		else if (RIGHT==oprat)
		{
			nextpos.y=curpos->y+1;
			nextpos.x=curpos->x;
			if (InMaze(nextpos.x, nextpos.y) && INWALL != maze[nextpos.x][nextpos.y] 
				&& OUTWALL != maze[nextpos.x][nextpos.y])
			{
				GoToxy(curpos->x, curpos->y);
				printf(" ");
				Sleep(SLEEPTIME);
				curpos->y+=1;
				GoToxy(curpos->x, curpos->y);
				printf("1");
				Sleep(SLEEPTIME);
			}
			else
				continue;
		}
	}
	/*GoToxy(27, 36);	
	printf("1"); test whether the end of the maze is blank*/
	GoToxy(MAX_LTH+3, 0);
	if ('q'==oprat)
		printf("Come on buddy, it is not as hard as you think!\n");
	else
		printf("Good Job! You are as cool as me!\n");
}
