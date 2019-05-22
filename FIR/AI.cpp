#include"head.h"
int notused(int m,int n,char board[N][N][L]);
void Level_0_Rand(char board[N][N][L]);
void Level_1_Max_Min(char board[N][N][L]);
void Level_2_ABcut(char board[N][N][L]);

void AIPos(char board[N][N][L])
{
	Level_0_Rand(board);
	Level_1_Max_Min(board);
	Level_2_ABcut(board);
}

int notused(int m,int n,char board[N][N][L])
{
	if(board[m][n][1]==BC||board[m][n][1]==WC)
		return 0;
	return 1;
}

void Level_0_Rand(char board[N][N][L])
{
	srand(time(NULL));
	int m,n;
	while(1)
	{
		m=rand()%15;
		n=rand()%15;
		if(notused(m,n,board))
		{
			sprintf(board[m][n],"¡ð");
			break;
		}
	}
	Wlast.m=m;
	Wlast.n=n;
}

void Level_1_Max_Min(char board[N][N][L])
{
}

void Level_2_ABcut(char board[N][N][L])
{
}
