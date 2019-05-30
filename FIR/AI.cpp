#include"head.h"
#include"Evaluation.h"

int notused(int m,int n,char board[N][N][L]);
void Level_0_Rand(char board[N][N][L]);
void Level_01_Greedy(char board[N][N][L]);
void Level_1_Max_Min(char board[N][N][L]);
void Level_2_ABcut(char board[N][N][L]);
int EmulateValue(char board[N][N][L],int side,int m,int n);		//根据最后落子估值				side:BLACK or WHITE
int insight(int m,int n,char board[N][N][L]);				//判断是否在已下子的周围

void AIPos(char board[N][N][L])
{
	//Level_0_Rand(board);
	Level_01_Greedy(board);
	//Level_1_Max_Min(board);
	//Level_2_ABcut(board);
}

int notused(int m,int n,char board[N][N][L])
{
	if(board[m][n][1]==BC||board[m][n][1]==WC)
		return 0;
	return 1;
}

int insight(int m,int n,char board[N][N][L])
{
	int ii,ji;
	if(m-3<0)
		ii=0;
	else
		ii=m-3;
	if(n-3<0)
		ji=0;
	else
		ji=n-3;
	for(int i=ii;i<=m+3&&i<N;i++)
	{
		for(int j=ji;j<=n+3&&j<N;j++)
			if(board[i][j][1]==BC||board[i][j][1]==WC)
				return 1;
	}
	return 0;
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
			sprintf(board[m][n],"○");
			break;
		}
	}
	Wlast.m=m;
	Wlast.n=n;
}

void Level_01_Greedy(char board[N][N][L])
{
	int i,j,maxval=-1000000000,m,n;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(!notused(i,j,board))
				continue;
			if(!insight(i,j,board))
				continue;
			int tmpval=EmulateValue(board,WHITE,i,j);
			if(tmpval>maxval)
			{
				maxval=tmpval;
				m=i;
				n=j;
			}
		}
	}
	sprintf(board[m][n],"○");
	Wlast.m=m;
	Wlast.n=n;
}

void Level_1_Max_Min(char board[N][N][L])
{
}

void Level_2_ABcut(char board[N][N][L])
{
}

int EmulateValue(char board[N][N][L],int side,int m,int n)
{
	char tmpboard[N][N][L];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			strcpy(tmpboard[i][j],board[i][j]);
		}
	}
	if(side==WHITE)
	{
		sprintf(tmpboard[m][n],"○");
	}
	else
	{
		sprintf(tmpboard[m][n],"●");
	}
	return Evaluation(tmpboard,WHITE)-5*Evaluation(tmpboard,BLACK);				//这里的5是一个系数，表示电脑赌黑子和加白子的权重
}
