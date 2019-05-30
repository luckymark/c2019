#include"head.h"
#include"FindWinner.h"

int winner(char board[N][N][L])
{
	if(JudgeBlack(board))
		return BLACK;
	if(JudgeWhite(board))
		return WHITE;
	return 0;
}

int Left_Right(char board[N][N][L],int state)
{
	int posm=0,posn=0,PChar=0;
	switch(state)
	{
		case BLACK:
			{
				posm=Blast.m;
				posn=Blast.n;
				PChar=BC;
				break;
			}
		case WHITE:
			{
				posm=Wlast.m;
				posn=Wlast.n;
				PChar=WC;
				break;
			}
		default:;
	}
	int Left=0,Right=0;
	while(posn-Left>0)
	{
		if(board[posm][posn-Left-1][1]==PChar)
			Left++;
		else
			break;
	}
	while(posn+Right<14)
	{
		if(board[posm][posn+Right+1][1]==PChar)
			Right++;
		else
			break;
	}
	if(Left+Right+1>=5)
		return 1;
	else
		return 0;
}

int Up_Down(char board[N][N][L],int state)
{
	int posm=0,posn=0,PChar=0;
	switch(state)
	{
		case BLACK:
			{
				posm=Blast.m;
				posn=Blast.n;
				PChar=BC;
				break;
			}
		case WHITE:
			{
				posm=Wlast.m;
				posn=Wlast.n;
				PChar=WC;
				break;
			}
		default:;
	}
	int Up=0,Down=0;
	while(posm-Up>0)
	{
		if(board[posm-Up-1][posn][1]==PChar)
			Up++;
		else
			break;
	}
	while(posm+Down<14)
	{
		if(board[posm+Down+1][posn][1]==PChar)
			Down++;
		else
			break;
	}
	if(Up+Down+1>=5)
		return 1;
	else
		return 0;
}

int Left_Up(char board[N][N][L],int state)
{
	int posm=0,posn=0,PChar=0;
	switch(state)
	{
		case BLACK:
			{
				posm=Blast.m;
				posn=Blast.n;
				PChar=BC;
				break;
			}
		case WHITE:
			{
				posm=Wlast.m;
				posn=Wlast.n;
				PChar=WC;
				break;
			}
		default:;
	}
	int LU=0,RD=0;
	while(posn-LU>0&&posm-LU>0)
	{
		if(board[posm-LU-1][posn-LU-1][1]==PChar)
			LU++;
		else
			break;
	}
	while(posn+RD<14&&posm+RD<14)
	{
		if(board[posm+RD+1][posn+RD+1][1]==PChar)
			RD++;
		else
			break;
	}
	if(LU+RD+1>=5)
		return 1;
	else
		return 0;
}

int Left_Down(char board[N][N][L],int state)
{
	int posm=0,posn=0,PChar=0;
	switch(state)
	{
		case BLACK:
			{
				posm=Blast.m;
				posn=Blast.n;
				PChar=BC;
				break;
			}
		case WHITE:
			{
				posm=Wlast.m;
				posn=Wlast.n;
				PChar=WC;
				break;
			}
		default:;
	}
	int LD=0,RU=0;
	while(posm+LD<14&&posn-LD>0)
	{
		if(board[posm+LD+1][posn-LD-1][1]==PChar)
			LD++;
		else
			break;
	}
	while(posn+RU<14&&posm-RU>0)
	{
		if(board[posm-RU-1][posn+RU+1][1]==PChar)
			RU++;
		else
			break;
	}
	if(LD+RU+1>=5)
		return 1;
	else
		return 0;
}

int JudgeBlack(char board[N][N][L])
{
	return Left_Right(board,BLACK)||Up_Down(board,BLACK)||Left_Up(board,BLACK)||Left_Down(board,BLACK);
}

int JudgeWhite(char board[N][N][L])
{
	return Left_Right(board,WHITE)||Up_Down(board,WHITE)||Left_Up(board,WHITE)||Left_Down(board,WHITE);
}
