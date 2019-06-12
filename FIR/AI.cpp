#include"head.h"
#include"Evaluation.h"
#include"AI.h"

void AIPos(char board[N][N][L])
{
	//Level_0_Rand(board);
	//Level_01_Greedy(board);
	//Level_1_Max_Min(board);
	Level_2_ABcut(board);
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
	int i,j,maxval=-1000000000,m,n;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(!notused(i,j,board))
				continue;
			if(!insight(i,j,board))
				continue;
			int tmpval=EmulateValueForMaxMin(board,i,j,2);				//以普通计算机的算力只能搜索两层
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

void Level_2_ABcut(char board[N][N][L])
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
			int tmpval=EmulateValueForABcut(board,i,j,2,maxval);
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

int EmulateValue(char board[N][N][L],int side,int m,int n)
{
/*
这一段评价函数是专门为贪心算法写的，极大极小值搜索时请不要用这个
*/
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
	return Evaluation(tmpboard,WHITE)-15*Evaluation(tmpboard,BLACK);				//这里的15是一个系数，表示电脑赌黑子和加白子的权重
}

int EmulateValueForMaxMin(char board[N][N][L],int m,int n,int depth)
{
	char tmpboard[N][N][L];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			strcpy(tmpboard[i][j],board[i][j]);
		}
	}
	if(!(depth%2))
	{
		sprintf(tmpboard[m][n],"○");
	}
	else
	{
		sprintf(tmpboard[m][n],"●");
	}
	if(depth==1)
		return Evaluation(tmpboard,WHITE)-9*Evaluation(tmpboard,BLACK);
	if(!(depth%2))													//depth为奇数表示在MIN层，为偶数表示在MAX层
	{
		int tmpm=0,tmpn=0,valmin=1000000000;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!notused(i,j,tmpboard))
					continue;
				if(!insight(i,j,tmpboard))
					continue;
				int tmpmin=EmulateValueForMaxMin(tmpboard,i,j,depth-1);
				if(tmpmin<valmin)
				{
					valmin=tmpmin;
					tmpm=i;
					tmpn=j;
				}
			}
		}
		sprintf(tmpboard[tmpm][tmpn],"●");
	}
	else
	{
		int tmpm=0,tmpn=0,valmax=-1000000000;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!notused(i,j,tmpboard))
					continue;
				if(!insight(i,j,tmpboard))
					continue;
				int tmpmax=EmulateValueForMaxMin(tmpboard,i,j,depth-1);
				if(tmpmax>valmax)
				{
					valmax=tmpmax;
					tmpm=i;
					tmpn=j;
				}
			}
		}
		sprintf(tmpboard[tmpm][tmpn],"○");
	}
	return Evaluation(tmpboard,WHITE)-9*Evaluation(tmpboard,BLACK);
}

int EmulateValueForABcut(char board[N][N][L],int m,int n,int depth,int lastval)
{
	char tmpboard[N][N][L];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			strcpy(tmpboard[i][j],board[i][j]);
		}
	}
	if(!(depth%2))
	{
		sprintf(tmpboard[m][n],"○");
	}
	else
	{
		sprintf(tmpboard[m][n],"●");
	}
	if(depth==1)
		return Evaluation(tmpboard,WHITE)-9*Evaluation(tmpboard,BLACK);
	if(!(depth%2))													//depth为奇数表示在MIN层，为偶数表示在MAX层
	{
		int tmpm=0,tmpn=0,valmin=1000000000;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!notused(i,j,tmpboard))
					continue;
				if(!insight(i,j,tmpboard))
					continue;
				int tmpmin=EmulateValueForABcut(tmpboard,i,j,depth-1,valmin);
				if(tmpmin<lastval)				//Got Problem here
					return lastval;
				if(tmpmin<valmin)
				{
					valmin=tmpmin;
					tmpm=i;
					tmpn=j;
				}
			}
		}
		sprintf(tmpboard[tmpm][tmpn],"●");
	}
	else
	{
		int tmpm=0,tmpn=0,valmax=-1000000000;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(!notused(i,j,tmpboard))
					continue;
				if(!insight(i,j,tmpboard))
					continue;
				int tmpmax=EmulateValueForABcut(tmpboard,i,j,depth-1,lastval);
				if(tmpmax>lastval)				//Got Problem here
					return lastval;
				if(tmpmax>valmax)
				{
					valmax=tmpmax;
					tmpm=i;
					tmpn=j;
				}
			}
		}
		sprintf(tmpboard[tmpm][tmpn],"○");
	}
	return Evaluation(tmpboard,WHITE)-9*Evaluation(tmpboard,BLACK);
}
